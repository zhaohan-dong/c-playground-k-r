/* exercise 3-1 binary search with one test inside loop */

#include<stdio.h>
#include<time.h>

int binsearch(int x, int v[], int n);
int binsearchnew(int x, int v[], int n);

int main(void) {
	int x, v[10000], n, i;
	int result1, result2;
	clock_t start, end, startn, endn; // test time
	// initialize parameters
	x = 5;
	for (i = 0; i < 10000; ++i)
		v[i] = i;
	n = 10000;

	start = clock();
	result1 = binsearch(x, v, n);
	end = clock();

	startn = clock();
	result2 = binsearchnew(x, v, n);
	endn = clock();

	printf("Original binary search completed in: %.10f sec\n", (double) (end - start) / CLOCKS_PER_SEC);
	printf("Result: %d\n", result1);
	printf("New binary search completed in: %.10f sec\n", (double) (endn - startn) / CLOCKS_PER_SEC);
	printf("Result: %d\n", result1);

    return 0;
}

int binsearchnew(int x, int v[], int n)
{
	int low, high, mid;
	
	low = 0;
	high = n - 1;
	while ((low <= high) && (x != v[mid])) {
		if (x < v[mid])
			high = mid - 1;
		else
			low = mid + 1;
		mid = (low + high) / 2;
	}
	if (x == v[mid])
		return mid;
	else
    	return -1;
}


int binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low+high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else	/* found match */
			return mid;
	}
	return -1;	/* no match */
}