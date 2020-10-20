# include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,s=0,j;

    cin>>n;

    int arr[n];             //Array elements representing the souvenirs

    for(i=0;i<n;i++){

        cin>>arr[i];

        s=s+arr[i];
    }

    int brr[n+1][s/3+1];            //2-D array where rows represent number of souvenirs and columns represent the partition sum among 3 friends

    if(s%3==0)
    {

    for(i=0;i<=n;i++)
        brr[i][0]=1;

    for(j=1;j<=s/3;j++)
        brr[0][j]=0;

    for(i=1;i<=n;i++)
    {

        for(j=1;j<=s/3;j++)
        {
            brr[i][j]=brr[i-1][j];

            if(arr[i-1]<=j)
                brr[i][j]=brr[i][j]||brr[i-1][j-arr[i-1]];
        }
    }

    cout<<brr[n][s/3];       //answer will be either 1 or 0 representing whether evenly distribution will take place or not

    }
    else
    cout<<"0";              //Souvenirs cannot be evenly distributed among 3 friends

    return 0;
}
