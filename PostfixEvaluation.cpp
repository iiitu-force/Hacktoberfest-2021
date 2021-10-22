#include<iostream>
#include<stack>
using namespace std;

int operation(int v1, int v2, char optor){
if(optor == '+'){
return (v1 + v2);
}
else if(optor == '-'){
return (v1 - v2);
}
else if(optor == '*'){
return (v1 * v2);
}
else if(optor == '/'){
return (v1 / v2);
} else
return (v1 ^ v2);
}


int main(){
 string s;
 cin>>s;
 stack<int> st;
 for(int i=0;i<s.length();i++){
 char ch = s[i];
 if(ch >= '0' && ch <= '9'){
 st.push(ch - '0');
 } else{
 char v2 = st.top();
 st.pop();
 char v1 = st.top();
 st.pop();
 int ans = operation(v1,v2,ch);
 char push = (char)ans;
 st.push(push);
 }
 }
 cout<<st.top()<<'\n';
}
