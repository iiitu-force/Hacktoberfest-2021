
#include <iostream>
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
int ternarySearch(int arr[], int l, int h, int x)
{
	if(l <= h)
	{
		int mid1 = l + (h - l)/3;
		int mid2 = mid1 + (h - l)/3;
		// if element is present at mid1
		if(arr[mid1] == x)
		return mid1;
		// if the element is present at mid2
		if(arr[mid2] == x)
		return mid2;
		// the element is present in left one-third sub array
		if(arr[mid1] > x)
		return ternarySearch(arr, l, mid1 - 1, x);
		// the element is present in right one-third sub array
		if(arr[mid2] < x)
		return ternarySearch(arr, mid2 + 1, h, x);
		// the element is present in the middle sub array
		return ternarySearch(arr, mid1 + 1, mid2 - 1, x);
	}
	// element not present in the array
	return -1;
}

int main()
{
	int arr[] = {1, 4, 5, 7, 10, 15, 34, 38};
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 0;
	cin >> x;
	cout << ternarySearch(arr, 0, n - 1, x);
	return 0;
}
  
