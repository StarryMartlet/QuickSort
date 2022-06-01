﻿#include <iostream>
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

void quickSortrandom(int arr[], int low, int high);

int partition(int arr[], int low, int high)
{
	// pivot
	int pivot = arr[high];

	
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		
		if (arr[j] <= pivot) {    // if (arr[j] >= pivot) descending!!!

	
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

// Generates Random Pivot, swaps pivot with
// end element and calls the partition function
int partition_r(int arr[], int low, int high)
{
	
	srand(time(NULL));
	int random = low + rand() % (high - low);

	// Swap A[random] with A[high]
	swap(arr[random], arr[high]);

	return partition(arr, low, high);
}


void quickSortrandom(int arr[], int low, int high)
{
	if (low < high) {

		/* pi is partitioning index,
		arr[p] is now
		at right place */
		int pi = partition_r(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSortrandom(arr, low, pi - 1);
		quickSortrandom(arr, pi + 1, high);
	}
}

/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
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
	quickSortrandom(sortThisArray, 0, n - 1);
	
	time_t t;
	srand((unsigned)time(&t));


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


	for (int i = 0; i < SIZE; i++)
	{
		cout << setw(8) << sortThisArray[i];
	}
	cout << endl;
	delete[]arr;
	end = clock();


	printf("The above code block was executed in %.4f second(s)\n", ((double)end - start) / ((double)CLOCKS_PER_SEC));
	return 0;

}
