#include <stdio.h>

int rsum(int sum, int *array, int size)
{
	if (size == 0) // Base case
		return (sum);
	else // Recursive case
		rsum(sum + *array, (array+1), (size-1));
}

int lsum(int sum, int *array, int size)
{
	while (size) // Base case
	{
		sum += *array;
		array++;
		size--;
	}
	return (sum);
}

int main()
{
	int array[3] = {2, 4, 6};

	int sum = 0;
	sum = rsum(sum, array, 3);
	printf("Recursion: %i\n", sum);
	sum = 0;
	sum = lsum(sum, array, 3);
	printf("Loop: %i\n", sum);
}
