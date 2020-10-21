#include <iostream>
#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int interpolationSearch(int arr[], int l, int h, int x)
{
	int pos;
	if(l <= h && arr[l] <= x && arr[h] >= x)
	{
		// determining the probe position using probe position formula
		pos = l + ((double)(h - l) * (x - arr[l])/(arr[h] - arr[l]));
		// if the element is found
		if(arr[pos] == x)
		return pos;
		// the element is present in right half array
		if(arr[pos] < x)
		return interpolationSearch(arr, pos + 1, h, x);
		// the element is present in left half array
		if(arr[pos] > x)
		return interpolationSearch(arr, l, pos - 1, x);
	}
	return -1;
}

int main()
{
	int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 0;
	cin >> x;
	cout << interpolationSearch(arr, 0, n - 1, x);
	return 0;
}
