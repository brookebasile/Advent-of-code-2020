#include <stdio.h>
#include <errno.h>

#define MAXLEN 200

int sort (int *);

int main()
{
	/*
	 * opening a file returns a ptr to an object of
	 * type FILE: records info necessary to control
	 * the stream
	 * When a program begins execution, the 3 streams stdin,
	 * stdout, and stderr are already open
	 */
	FILE *file = fopen("input.txt", "r");
	
	if (file == NULL) {
		printf("Error opening file");
		return ENOENT;
	}

	int integers[MAXLEN];
	int i = 0;
	int num, ans;

	/*
	 * fscanf returns the number of input items converted & assigned
	 * reads line by line, so everything worked OK if ret == 1
	 */
	while (fscanf(file, "%d", &num) == 1) {
		integers[i] = num;
		i++;
	}
	fclose(file);

	ans = sort(integers);
	printf("%d\n", ans);

	return 0;
}

int sort(int *a)
{
	int target;
	int ret = 0;
	int n = 0;

	do {	
		target = a[n];
		for (int i = n + 1; i < MAXLEN; i++) {
			if (target + a[i] == 2020)
				ret = target * a[i];
			}
		n++;
	} while (ret == 0 && n < MAXLEN);

	return ret;
}
