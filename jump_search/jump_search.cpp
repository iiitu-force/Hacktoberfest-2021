/*
Like Binary Search, Jump Search is a searching algorithm for sorted arrays. 
The basic idea is to check fewer elements (than linear search) by jumping ahead 
by fixed steps or skipping some elements in place of searching all elements. 
Time complexity : O(√n)
Space complexity : O(1)
*/

#include <bits/stdc++.h> 
using namespace std; 


int jumpSearch(int arr[], int k, int n) 
{ 
	int step = sqrt(n); 

	int prev = 0; 
	while (arr[min(step, n)-1] < k) 
	{ 
		prev = step; 
		step += sqrt(n); 
		if (prev >= n) 
			return -1; 
	} 
 
	while (arr[prev] < k) 
	{ 
		prev++; 
		if (prev == min(step, n)) 
			return -1; 
	} 

	if (arr[prev] == k) 
		return prev; 

	return -1; 
} 


int main() 
{ 
	cout << "Enter length of the array : ";
	int length;
	cin >> length;

	cout << "Enter integer to be searched : ";
	int k;
	cin >> k;

	cout << "Enter elements of the array : ";
	int arr[length];
	for (int i = 0;  i < length;  i++)
	{
		cin >> arr[i];
	}
	
	int index = jumpSearch(arr, k, length); 

	cout << "Number " << k << " is at index " << index; 
	return 0; 
} 

/*
OUTPUT :

Enter length of the array : 10
Enter integer to be searched : 5
Enter elements of the array : 1 2 4 4 5 7 8 9 9 10
Number 5 is at index 4
*/
