#include <stdio.h>

void swap(int *a, int * b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int left, int right) 
{
    // int arr[] = {8, 2, 4, 7, 1, 3, 9, 6, 5};
	// //           0  					    8
    // int arr[] = [i] [8j], 2, 4, 7, 1, 3, 9, 6, [5] 

    int pivot = arr[right];
    int i = left - 1;
	int j = left;
	while (j < right)
	{
        if (arr[j] < pivot)
			swap(&arr[++i], &arr[j]);
		j++;
	}

	swap(&arr[i + 1], &arr[right]);

    return i + 1;
}

void quicks(int arr[], int left, int right) 
{
    if (left < right) 
	{
        int pivot = partition(arr, left, right);
        quicks(arr, left, pivot - 1);   // Sort elements before pivot
        quicks(arr, pivot + 1, right);  // Sort elements after pivot
    }
}

int main() 
{
    int arr[] = {8, 2, 4, 7, 1, 3, 9, 6, 5};
	//           0  1  2  3  4  5  6  7  8
	//           0  1  2  3  4  5  6  7  8

    int end = sizeof(arr) / sizeof(arr[0]);

    quicks(arr, 0, end - 1);

    printf("Sorted array: ");
    for (int beg = 0; beg < end; beg++) 
	{
        printf("%d ", arr[beg]);
    }
    return 0;
}
