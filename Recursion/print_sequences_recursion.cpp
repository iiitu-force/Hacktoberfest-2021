// C++ program to  print all increasing sequences of 
// length 'k' such that the elements in every sequence 
// are from first 'n' natural numbers. 
#include<iostream> 
using namespace std; 
void printArr(int arr[], int k) 
{ 
    for (int i=0; i<k; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
}  
void printSeqUtil(int n, int k, int &len, int arr[]) 
{ 
       if (len == k) 
    { 
        printArr(arr, k); 
        return; 
    } 
     int i = (len == 0)? 1 : arr[len-1] + 1; 
      len++; 
     while (i<=n) 
    { 
        arr[len-1] = i; 
        printSeqUtil(n, k, len, arr); 
        i++; 
    }
    len--; 
} 
void printSeq(int n, int k) 
{ 
    int arr[k];   
    int len = 0; 
    printSeqUtil(n, k, len, arr); 
} 
int main() 
{ 
    int k = 3, n = 7; 
    printSeq(n, k); 
    return 0; 
} 
