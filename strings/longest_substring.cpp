#include<bits/stdc++.h>
using namespace std ;

int main() {

	//String of which we want to find substring
	string str ;
	getline(cin , str );

	//A vector that will store the various possible consecutive strings
	vector<char> v;

	//Will hold the length of longest consecutive string
	int count = 0 ;

	//We will traverse each char in string and start string it in vector till the char doesn't repeat
	for( auto x : str ) {

		auto it = find(v.begin() , v.end() , x );

		//If it is present means it is repeating 
		if(it != v.end()) {
			int idx = it - v.begin();


			//So we will delete the char which is repeated in the substring and preceding 
			//as substring should be consecutive
			for( int i = 0 ; i <= idx ; i++ ) {
				v.erase( it);
				it--;
			}
		}

		//New character pushed to the sub string every time as we move from left to right
		v.push_back(x);

		//it check if current substring size is greater than any previous substring
		if( v.size() > count ){
			count = v.size();
		}
	}


	cout << count << endl ;

	return 0 ;
}