#include<bits/stdc++.h>
using namespace std;
int longestsub(string x,string y,int n,int m){
    int lcs[n+1][m+1];
    int result=0;//store the maximum value of 2d array
    for(int i=0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0||j==0){
                lcs[i][j]=0;
            }
            else if(x[i-1]==y[j-1]){
            lcs[i][j]=1+lcs[i-1][j-1];
            result =max(result,lcs[i][j]);
            }
            else lcs[i][j]=0;
        }
    }
    return result;
}
int main() {
      string x="abcdaftt";
      string y="zbcdf";
      int n=x.length();
      int m=y.length();
      cout<<"LCS of given strings is: "<<" ";
      cout<<longestsub(x,y,n,m)<<endl;
  
  return 0;
} 
