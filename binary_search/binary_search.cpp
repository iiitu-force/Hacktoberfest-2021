#include<bits/stdc++.h>
using namespace std;

void print_array(int [],int);

int main(){
  int a[]={3,4,2,8,7,6,9};
  int a_size=sizeof(a)/sizeof(a[0]);
  cout<<"The array is :";
  print_array(a,a_size);
  cout<<"\nLet's say we want to search for 8 in the array"<<endl;
  cout<<"\nSo we first sort the array"<<endl;
  sort(a,a+a_size);
  cout<<"The array after sorting is :";
  print_array(a,a_size);
  cout<<"\n\n Now lets do the binary search for 8"<<endl;
  if(binary_search(a,a + 10,8)){
    cout<<"Element found in the array"<<endl;
  }
  else{
    cout<<"Element not found in the array"<<endl;
  }
  cout<<"\n\n Now lets do the binary search for 10"<<endl;
  if(binary_search(a,a + 10,10)){
    cout<<"Element found in the array"<<endl;
  }
  else{
    cout<<"Element not found in the array"<<endl;
  }
  return 0;
}

void print_array(int a[],int array_size){
  for(int i=0;i<array_size;i++){
    cout<<a[i]<<" ";
  }
}
