// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution {
public:
    vector<int> factorial(int n)
    {
        vector<int> fact(1e4, 0);
        fact[0] = 1;
        int carry = 0;
        int len = 1;
    
        for(int i = 2;  i <= n;  i++)
        {
            int j = 0;
            int temp = 0;
            while(j < len || temp)
            {
                if(j == len)
                    len++;
                temp = fact[j] * i + temp;
                fact[j] = temp % 10;
                temp /= 10;
                j++;
            }
        }
        vector<int> res;
        for(int i = len-1;  i >= 0;  i--)
            res.push_back(fact[i]);
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends 
