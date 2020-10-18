#include<bits/stdc++.h>
using namespace std;

int power(int a, int b)
{
    int res = 1;

    if(b==0)
    {
        return res;
    }

    while(b>0)
    {
    if(b%2)
    {
        res *= a;
        b--;
    }

    else{
        res = a*a;
        b /= 2;
    }

    }
    return res;
}

int main()
{
    int x = 2, y = 5;

    cout<<power(x,y);
}
