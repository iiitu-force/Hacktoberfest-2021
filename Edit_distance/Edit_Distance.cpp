# include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2;
    int l1,l2,i,j,a,b,c,d,e;

    cin>>s1>>s2;        //Enter string 1 and string 2

    l1=s1.size();
    l2=s2.size();

    int arr[l1+1][l2+1];            //2-D array representing the length of two string in rows and columns

    arr[0][0]=0;                    //value at l1=0 and l2=0

    for(j=1;j<=l2;j++)
        arr[0][j]=s2[j-1];          //insertion of characters in columns of row0 of string2

    for(i=1;i<=l1;i++)
        arr[i][0]=s1[i-1];          //insertion of characters in rows of column0 of string1

    for(i=1;i<=l1;i++)
    {
        for(j=1;j<=l2;j++)
        {
            if(j-1==0)
                a=i+1;
            else
                a=arr[i][j-1]+1;

            if(i-1==0)
                b=j+1;
            else
                b=arr[i-1][j]+1;

            if(s2[j-1]==s1[i-1])
            {
                if((i-1==0)&&(j-1!=0))
                    c=j-1;
                else
                if((j-1==0)&&(i-1!=0))
                    c=i-1;
                else
                    c=arr[i-1][j-1];
            }
            else
            {
                if((i-1==0)&&(j-1!=0))
                    c=j;
                else
                if((j-1==0)&&(i-1!=0))
                    c=i;
                else
                    c=arr[i-1][j-1]+1;
            }

            d=min(a,b);
            e=min(d,c);

            arr[i][j]=e;
        }
    }

    cout<<arr[l1][l2];      //edit distance
    return 0;
}
