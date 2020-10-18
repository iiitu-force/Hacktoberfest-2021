#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void merge(int[], int , int, int);
void mergesort(int[], int, int);
void printarray(int[], int);

int main()
{
	int arr[] = {1, 66, 27, 99, 30, 38, 75, 49, 48};
	int n = sizeof(arr) / sizeof(arr[0]);
	mergesort(arr, 0, n - 1);
	printarray(arr, n);
	return 0;
}

void mergesort(int arr[], int l, int r)
{
	if(l < r)
	{
		int mid = l + (r - l) / 2;
		
		mergesort(arr, l, mid);
		mergesort(arr, mid + 1, r);
		
		merge(arr, l, mid, r);
	}
}
void merge(int arr[], int l, int m, int r)
{
	int i = 0, j = 0, k = 0;
	int nl = m - l + 1;  // size of left array
	int nr = r - m;   // size of right array
	
	// creating temporary array
	int  left[nl], right[nr];
	
	// copying data to temp arrays
	for(i = 0; i < nl; i++)
	left[i] = arr[l + i];
	for(j = 0; j < nr; j++)
	right[j] = arr[m + 1 + j];
	
	// merging temp arrays back to arr
	i = 0;     // Initial index of first subarray
	j = 0;     // Initial index of second subarray
	k = l;     // Initial index of merged subarray
	
	while(i < nl && j < nr)
	{
		if(left[i] <= right[j])
		{
			arr[k] = left[i];
			i++;
		}
		else
		{
			arr[k] = right[j];
			j++;
		}
		k++;
	}
	
	// copying the remaining element of left array, if left
	while(i < nl)
	{
		arr[k] = left[i];
		i++;
		k++;
	}
	
	// copying the remaining element of right array, if left
	while(j < nr)
	{
		arr[k] = right[j];
		k++;
		j++;
	}
}

void printarray(int arr[], int n)
{
	for(int i = 0; i < n; i++)
	cout << arr[i] << " ";
	cout << endl;
}
