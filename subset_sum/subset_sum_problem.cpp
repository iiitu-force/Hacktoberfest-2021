//THIS PROGRAM WILL FIND THE REQUIRED SUBSET SUM IN GIVEN ARRAY 

#include<bits/stdc++.h>
#define ll long long
#define test while(t--)
#define mod 1e9
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define name using namespace std;
name

//This function find the subset sum
bool subset(int arr[],int size,int sum){

// If sum left turns zero or array is completely traversed function will return
   if(sum==0)
   return 1;

   if(size==0)
   return 0;

// recursively check the elements forming the subset sum or not  
   if(arr[size-1]<=sum)
   return subset(arr,size-1,sum-arr[size-1]) || subset(arr,size-1,sum);

   else
   return subset(arr,size-1,sum);
}


int main(){
   int n;
   cout<<"enter no. of elements you want to enter in array\n";
   cin>>n;
   int arr[n];
   cout<<"enter "<<n<<" elements\n";
   for (size_t i = 0; i < n; i++)
   cin>>arr[i];

   int sum;  
   cout<<"enter sum value you want to find in array\n";
   cin>>sum;

   int size = sizeof(arr)/sizeof(arr[0]);
    
// if function returns 1 implies subset sum is present
    if(subset(arr,size,sum))
    cout<<"subset sum is present in array";

// if function returns 0 implies subset sum is not present
    else cout<<"subset sum is not present";
    
 return 0;
}