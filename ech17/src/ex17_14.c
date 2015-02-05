/*
 * a is an array of 100 integers.
 * write a call of qsort that sorts only the last 50 elements in a.
 */

#include <stdio.h>
#include <stdlib.h>

void qsort(void *base, size_t nmemb, size_t size, int (*compar) (const void *, const void *));
int sorty_sort(const void *p, const void *q);

int main(void)
{
	int array[100] = {0};
	int i, j;

	printf("Let me initialize an array of 100 elements for you.\n");
	for (i = 100, j = 0; i > 0; i--, j++)
		array[j] = i;

	printf("Now I will sort the last 50 elements from lowest to highest.");
	qsort(&array[50], 50, sizeof(int), sorty_sort);

	return 0;
}

int sorty_sort(const void *p, const void *q)
{
	int *p1 = p;
	int *q1 = q;

	if (*p1 > *q1)
		return 1;

	if (*p1 == *q1)
		return 0;

	if (*p1 < *q1)
		return -1;
}
