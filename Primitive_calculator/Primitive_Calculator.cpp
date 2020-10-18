#include <bits/stdc++.h>
using namespace std;

int ans[1000010];

int main()
{
    ans[0] = 0;             //when n=0
    ans[1] = 0;             //when n=1
    ans[2] = 1; ans[3] = 1;

    int n, temp;
    cin >> n;

    for (int i = 4; i <= n; i++) {
        temp = ans[i-1];
        if (i % 2 == 0) {
            temp = min(temp, ans[i/2]);
        }
        if (i % 3 == 0) {
            temp = min(temp, ans[i/3]);
        }
        ans[i] = temp + 1;
    }

    cout <<ans[n]<<endl;        //number of minimum steps
    vector <int> rslt;

    while (n > 1) {
       rslt.push_back(n);
       temp = n-1;
       if (n % 2 == 0 && ans[temp] > ans[n/2]) {
            temp = n/2;
       }
       if (n % 3 == 0 && ans[temp] > ans[n/3]) {
            temp = n/3;
       }
       n = temp;
    }
    rslt.push_back(1);
    temp = rslt.size();

    for (int i = temp-1; i >= 0; i--) {
        cout <<rslt[i]<<" ";
    }
    return 0;
}
