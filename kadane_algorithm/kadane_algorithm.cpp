/*
Problem Statement :
Write an efficient program to find the sum of contiguous subarray within a one-dimensional array of numbers which has the largest sum.
*/ 


#include<bits/stdc++.h>
using namespace std;

int main()
{
   
    int length;
    cin >> length;
    int arr[length], sum = 0, ans = INT_MIN;
    for(int i=0; i<length; i++)
    {
        cin >> arr[i];
            
        sum += arr[i];
        ans = max(ans, sum);
        if(sum < 0)
            sum = 0;
    }
    
    cout<<ans<<endl;
    return 0;
}

/*
INPUT :
5
1 2 3 -2 5

OUTPUT :
9
*/
