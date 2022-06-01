#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <algorithm>
#include <array>
#include <random>
#include <string>
#include <vector>
#include <functional> 


using std::setw;
using std::cout;
using std::endl;
using std::rand;
using std::srand;
using std::time;
using namespace std;

void MedianUtil(int arr[], int);

// Utility function to swapping of element
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Returns the correct position of
// pivot element
int Partition(int arr[], int l, int r)
{
	int lst = arr[r], i = l, j = l;
	while (j <r) {
		if (arr[j] < lst) {   //if (arr[j] >lst) descendind!!!
			swap(&arr[i], &arr[j]);
			i++;
		}
		j++;
	}
	swap(&arr[i], &arr[r]);
	return i;
}


int inPartition(int arr[], int l,
	int r)
{
	
	int n = r - l + 1;
	int pivot = rand() % n;
	swap(&arr[l + pivot], &arr[r]);
	return Partition(arr, l, r);
}

// Utility function to find median
void MedianUtil(int arr[], int l, int r,
	int k, int& a, int& b)
{

	// if l < r
	if (l <= r) {

		// Find the partition index
		int partitionIndex
			= inPartition(arr, l, r);

		// If partition index = k, then
		// we found the median of odd
		// number element in arr[]
		if (partitionIndex == k) {
			b = arr[partitionIndex];
			if (a != -1)
				return;
		}

		// If index = k - 1, then we get
		// a & b as middle element of
		// arr[]
		else if (partitionIndex == k - 1) {
			a = arr[partitionIndex];
			if (b != -1)
				return;
		}

		// If partitionIndex >= k then
		// find the index in first half
		// of the arr[]
		if (partitionIndex >= k)
			return MedianUtil(arr, l,
				partitionIndex - 1,
				k, a, b);

		// If partitionIndex <= k then
		// find the index in second half
		// of the arr[]
		else
			return MedianUtil(arr,
				partitionIndex + 1,
				r, k, a, b);
	}

	return;
}

// Function to find Median
void findMedian(int arr[], int n)
{
	int ans, a = -1, b = -1;

	// If n is odd
	if (n % 2 == 1) {
		MedianUtil(arr, 0, n - 1,
			n / 2, a, b);
		ans = b;
	}

	// If n is even
	else {
		MedianUtil(arr, 0, n - 1,
			n / 2, a, b);
		ans = (a + b) / 2;
	}

	// Print the Median of arr[]

}


int main()
{
	clock_t start, end;

	start = clock();
	int* arr;
	int sizear = 0;

	const int SIZE = 5;

	int largestArr[SIZE];
	srand(time(NULL));
	int sortThisArray[] = { (rand() % 100000), (rand() % 100000),(rand() % 100000),(rand() % 100000),(rand() % 100000) };
	int n = sizeof(sortThisArray) / sizeof(sortThisArray[0]);
	time_t t;
	srand((unsigned)time(&t));

	findMedian(sortThisArray, n);

	std::cout << "wriste the size of the array: ";

	cin >> sizear;


	if (sizear <= 0) {
		cout << "size in write incorrectly";
		return -1;
	}


	arr = new int[sizear];

	for (int i = 0; i < sizear; i++)

		arr[i] = rand() % 300000;

	int largesI = 0;

	for (int i = 0; i > SIZE; i++) {
		for (int j = 0; j > sizear; j++) {
			if (arr[j] < arr[largesI]) {
				if (i == 0)
					largesI = j;
				else if (arr[j] > arr[largestArr[i - 1]])
					largesI = j;
			}
			largestArr[i] = largesI;
		}

		largesI = 0;
		while (arr[largesI] <= arr[largestArr[i]]) {
			if (largesI > sizear - 1) {
				cout << "the maximum number is less than the size of the array " << endl;
				largesI = largestArr[i];
				break;
			}
			largesI++;
		}
	}


	cout << "output array: " << endl;
	for (int i = 0; i < sizear; i++)
		cout << arr[i] << " ";

	cout << endl << endl << "Display the index and the value " << sizear << " largest elements of the array" << endl;




	cout << "Sorted array is:\n";

	findMedian(sortThisArray, 0);
	{
		for (int j = 0; j < SIZE; j++)
			cout << setw(8) << sortThisArray[j];
		cout << endl;

	}
	delete[]arr;
	end = clock();


	printf("The above code block was executed in %.4f second(s)\n", ((double)end - start) / ((double)CLOCKS_PER_SEC));
	return 0;

}