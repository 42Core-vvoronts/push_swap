#include <stdio.h>


// int wrap_step(int vizero, int vi) 
// {
// 	int pi;
// 	int head = 1;
// 	int tail = 4;
// 	int len = 4;
// 	int max = 5;

// 	if (vi % len == 0) // return to the same position
// 		pi = vizero;
// 	else if (vizero == tail) // convert tail to head
// 	{
// 		vizero = head;
// 		vi += (len - 1);
// 	}
// 	else if (vi >= 0) // forward
// 		pi = (vizero + (vi % len)) % max;
// 	else // backwards
// 		pi = (vizero + (vi % len) + len) % max;
// 	return (pi);
// }

int wrap_step(int vizero, int vi) 
{
	int head = 1;
	int tail = 4;
	int len = 4;
	int max = 5;
	int shift;

	shift = 0;
	if (vi % len == 0)
		return (vizero);
	if (vizero == head && vi < 0)
		shift = len;
	else if (vizero == tail && vi < 0)
		shift = max;
	else if (vizero == tail && vi > 0)
	{
		vi -= 1;
		vizero = head;
	}
	return ((vizero + (vi % len) + shift) % max);
}

void test_wrap_step(int vizero, int vi, int expected_index, int expected_value, int arr[], const char* direction) {
    int result_index = wrap_step(vizero, vi);
    int result_value = arr[result_index];
    
    // Green check mark and red cross with color codes
    const char* green_check = "\033[0;32m✓\033[0m";
    const char* red_cross = "\033[0;31m✕\033[0m";
    
    const char* symbol = (result_index == expected_index && result_value == expected_value) ? green_check : red_cross;

    printf("%s %s %d: [%d] %d\n", symbol, direction, vi, result_index, result_value);

    // Check if we need to print the expected value when the result doesn't match
    if (symbol == red_cross) {
        printf("---expected [%d] %d\n", expected_index, expected_value);
    }
}

int main() {
	int arr[5] = {4, 5, 3, 7, 6};
	int head = 1;
	int tail = 4;

	// Test cases for head
	test_wrap_step(head, 0, 1, 5, arr, "head");
	test_wrap_step(head, 1, 2, 3, arr, "head");
	test_wrap_step(head, 4, 1, 5, arr, "head");
	test_wrap_step(head, 10, 3, 7, arr, "head");
	test_wrap_step(head, -1, 4, 6, arr, "head");
	test_wrap_step(head, -4, 1, 5, arr, "head");
	test_wrap_step(head, -10, 3, 7, arr, "head");

	// Test cases for tail
	test_wrap_step(tail, 0, 4, 6, arr, "tail");
	test_wrap_step(tail, -1, 3, 7, arr, "tail");
	test_wrap_step(tail, -4, 4, 6, arr, "tail");
	test_wrap_step(tail, -10, 2, 3, arr, "tail");
	test_wrap_step(tail, 1, 1, 5, arr, "tail");
	test_wrap_step(tail, 4, 4, 6, arr, "tail");
	test_wrap_step(tail, 10, 2, 3, arr, "tail");

	return 0;
}
