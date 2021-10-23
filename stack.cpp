//bracket checking
#include <bits/stdc++.h>
using namespace std;
#define MAXSIZE 100
struct lifo
{
    char st[MAXSIZE];
    int top;
};
typedef struct lifo sta;
void create(sta *s)
{
    s->top = -1;
}
void push (sta *s,char e)
{
    if(s->top == (MAXSIZE-1))
    {
        cout<<"stack overflow";
        exit(-1);
    }
    else
    {
        s->top++;
        s->st[s->top] = e;
    }
    
}
void pop(sta *s)
{
    if(s->top == -1)
    {
        cout<<"stack underflow";
        exit(-1);
    }
    else
    {
    s->top--;
    }
}
int isempty(sta *s)
{
    if(s->top==-1)
     return 1;
     else 
     return 0;
}
int isfull(sta *s)
{
    if(s->top == MAXSIZE-1)
     return 1;
     else 
     return 0;
}
int main() {
   sta A;
   sta *pi;
   pi = &A;
   create(&A);
   int n,i;
   i=0;
   string s;
   cout<<"Enter expression: ";
   cin>>s;
   while(i!=s.size())
  {
      if(s[i]==40 || s[i]==91 || s[i]==123)
       push(&A,s[i]);
      else if(pi->top!= -1)
      {
          if(((s[i]==')' && pi->st[pi->top]=='(')||(s[i]=='}' &&pi->st[pi->top]=='{')||(s[i]==']' && pi->st[pi->top]=='[')))
          pop(&A);
          else if(((s[i]==')' && pi->st[pi->top]!='(')||(s[i]=='}' &&pi->st[pi->top]!='{')||(s[i]==']' && pi->st[pi->top]!='[')))
          {
              cout<<"misbalance";
              break;
          }
      }
       i++;
  }
  if(i==s.size())
  cout<<"balance";
  
   return 0;
}