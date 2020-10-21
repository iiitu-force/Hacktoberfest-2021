 /*
Exponantial Search - 
It is muach better then binary search.
Useful for unbounded(infinite) array.
Time complexity - O(log2n)
Space complexity - if itretive O(1) if recursive O(log2n)
*/
 
int32_t main()
{
	IOS
	test
	{
		input(a)
		int k;
		cin >> k;

		if(a[0] == k)
		cout<<0<<endl;
		else
		{
			int i=1;
			while(i<n && a[i]<k)
			{
				i *= 2;
			}

			int low = i/2, high = min(i, n-1);

			while(low <= high)
			{
				int mid = low + (high-low)/2;

				if(a[mid] == k)
				{
					cout<<mid<<endl;
					break;
				}
				if(a[mid] > k)
				high = mid-1;
				else
				low = mid+1;
			}
		}
	}
	return 0;
}
