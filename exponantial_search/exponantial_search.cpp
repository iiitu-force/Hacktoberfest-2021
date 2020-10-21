/*
Exponantial Search - 
It is muach better than binary search.
Useful for unbounded(infinite) array.
Time complexity - O(log2n)
Space complexity - if itretive O(1) if recursive O(log2n)
*/


#include <iostream>
using namespace std;

int main()
{
	cout << "Enter length of the array : ";
	int length;
	cin >> length;
	cout << "Enter the integer to be searched : ";
	int k;
	cin >> k;

	cout << "Enter elements of the array : ";
	int arr[length];
	for (int i = 0;  i < length;  i++)
	{
		cin >> arr[i];
	}
	
	if(arr[0]  ==  length)
		cout << 0 << endl;
	else
	{
		int i = 1;
		while(i < length  &&  arr[i] < k)
		{
			i *= 2;
		}

		int low = i/2,  high = min(i, length-1);

		cout << "Integer is present at index : ";
		while(low <= high)
		{
			int mid = low + (high - low) / 2;

			if(arr[mid] == k)
			{
				cout << mid << endl;
				break;
			}
			if(arr[mid] > k)
		 		high = mid-1;
			else
				low = mid+1;
		}
	}
	return 0;
}

/*
OUTPUT :

Enter length of the array : 10
Enter the integer to be searched : 5
Enter elements of the array : 1 2 4 5 7 9 10 12 14 15
Integer is present at index : 3
*/
