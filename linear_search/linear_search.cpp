/*
A simple approch of searching 
Time complexity - O(n)
*/ 
 
#include <iostream>
using namespace std;

int search(int arr[], int length, int k)
{
	int i;
	for (i = 0;  i < length;  i++)
		if (arr[i] == k)
			return i;
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

	int result = search(arr, length, k);

	if (result == -1)
	{
		cout << "Element is not persent in the array!";
	}
	else
	{
		cout << "Element is present at index : " << result;
	}
	return 0;
}

/*
Enter length of the array : 10
Enter integer to be searched : 7
Enter elements of the array : 1 7 4 2 6 5 5 9 10 1
Element is present at index : 1 
*/
