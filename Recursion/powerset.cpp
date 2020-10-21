#include <bits/stdc++.h> 
using namespace std; 

void powerSet(string str, int index = -1, string cur = "") 
{ 
	int n = str.length(); 

	if (index == n) 
		return; 

	// printing current subset 
	cout << cur << "\n"; 

	// appending remaining characters to current subset 
	for (int i = index + 1; i < n; i++) { 

		cur += str[i]; 
		powerSet(str, i, cur); 

		// Once all subsets beginning with initial "cur" are printed remove the last character to consider a different prefix of subsets. 
		cur.erase(cur.size() - 1); 
	} 
	return; 
} 

int main() 
{ 
	string str = "abcdef"; 
	powerSet(str); 
	return 0; 
} 
