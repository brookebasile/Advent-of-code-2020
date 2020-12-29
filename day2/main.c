#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN 1000 

struct line {
	int min;
	int max;
	char letter;
	char password[100];
};

int parse(struct line *);

int main()
{
	struct line entries[MAXLEN];
	char buf[MAXLEN];
	int ret, tot;

	FILE *file = fopen("input.txt", "r");

	if (file == NULL) {
		printf("Error opening file");
		return ENOENT;
	}
	
	/*
	 * Organize input into array of structs
	 */
	tot = 0;

	for (int i = 0; fgets(buf, MAXLEN, file) != 0 && i < MAXLEN; i++) {
		sscanf(buf, "%d-%d %c: %s\n", &entries[i].min, &entries[i].max,
		       &entries[i].letter, entries[i].password);
		tot++;
	}
	fclose(file);
	
	if (tot != MAXLEN)
		return EINVAL;

	ret = parse(entries);
	printf("%d\n", ret);

	return 0;
}

int parse(struct line *entries)
{
	int ret = 0;

	for (int i = 0; i < MAXLEN; i++) {
		int count = 0;

		for (int n = 0; entries[i].password[n] != '\0'; n++) {
			if (entries[i].password[n] == entries[i].letter)
				count++;
		}
		
		if (count >= entries[i].min && count <= entries[i].max)
			ret++;
	}
	return ret;
}
