/*
 *  ex12_10.c
 *  xch12
 *
 *	rewrite to use pointer arithmetic vs array subscript
 */

//initial
int sum_array(int a[], int n)
{
	int i, sum;
	
	sum = 0;
	for (i = 0; i < n; i++)
		sum += a[i];
	return sum;
}

//pointers
int sum_array(int a[], int n)
{
	int *p, sum;
	
	for (p = a, sum = 0; p < a+n; p++)
		sum += *p;
	return sum;
}
