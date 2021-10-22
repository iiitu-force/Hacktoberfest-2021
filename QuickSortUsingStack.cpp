#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int partition(int arr[], int low, int high)
  {
    int pivot = arr[high];
    int pi = low;
    for (int i = low; i < high; i++)
    {
    if (arr[i] <= pivot)
      {
        swap(arr[i], arr[pi]);
        pi++;
      }
    }
    swap (arr[pi], arr[high]);
    return pi;
    }
    
    void iterativeQuicksort(int arr[], int n)
    {
    stack<pair<int, int>> st;
    int low = 0;
    int high = n - 1;
    st.push(make_pair(low, high));
    
    while (!st.empty())
    {
    low = st.top().first, high = st.top().second;
    st.pop();
    int pivot = partition(arr, low, high);
    
    if (pivot - 1 > low) {
    st.push(make_pair(low, pivot - 1));
    }
    if (pivot + 1 < high) {
    st.push(make_pair(pivot + 1, high));
    }
    }
    }
    
    
    int main()
    {
      int n;
      cin>>n;
      int arr[n];
      for(int i=0; i<n; i++){
      cin>>arr[i];
      }
      iterativeQuicksort(arr, n);

      for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
      }
      return 0;
 }
