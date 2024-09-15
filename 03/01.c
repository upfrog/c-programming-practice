/*
Exercise 3-1. Ourbinary serach makes two test inside the loop, when one would suffice (at the price of more tests outside). Write a version with only one test inside the loop and measure the difference in run-time.
*/


#include <stdio.h>


int binsearch(int, int[], int);


int main()
{
	//This is to make the test take enough time to be usefully measurable
	int len = 1000000;

	int inputarray[len];
    for (int i = 0; i < len; i++) {
        inputarray[i] = i + 1;  // {1, 2, 3, ..., 1000}
    }

	for (int j = 0; j < 20; ++j)
	{
		for (int i = 0; i < len; ++i)
		{
			if (binsearch(i+1, inputarray, len) != i)
			{
				printf("TEST FAILED FOR INDEX %d\n", i);
			}
		}
	}
}	



int binsearch(int target, int arr[], int len)
{
	int low = 0;
	int high = len;

	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (arr[mid] < target)
		{
			low = mid + 1;
		}
		else if (arr[mid] > target)
		{
			high = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1; //target not found in arr.

}

//original binsearch
/*
int binsearch(int target, int arr[], int len)
{
	int low = 0;
	int high = len;

	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (arr[mid] < target)
		{
			low = mid + 1;
		}
		else if (arr[mid] > target)
		{
			high = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1; //target not found in arr.

}
*/
