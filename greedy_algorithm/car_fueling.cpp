/*

Problem Statement : 
You are going to travel to another city that is located 𝑑 miles away from your home city. Your car can travel
at most 𝑚 miles on a full tank and you start with a full tank. Along your way, there are gas stations atdistances stop1
,stop2, . . . ,stop𝑛 from your home city. What is the minimum number of refills needed?

Problem Description : 
Input Format - The first line contains an integer 𝑑. The second line contains an integer 𝑚. The third line
specifies an integer 𝑛. Finally, the last line contains integers stop1,stop2, . . . ,stop𝑛.

Output Format -  Assuming that the distance between the cities is 𝑑 miles, a car can travel at most 𝑚 miles
on a full tank, and there are gas stations at distances stop1,stop2, . . . ,stop𝑛 along the way, output the
minimum number of refills needed. Assume that the car starts with a full tank. If it is not possible to
reach the destination, output −1.

Constraints. 1 ≤ 𝑑 ≤ 105. 1 ≤ 𝑚 ≤ 400. 1 ≤ 𝑛 ≤ 300. 0 < stop1 < stop2 < · · · < stop𝑛 < 𝑑.

*/

#include <iostream>
#include <vector>

using namespace std ;

int compute_min_refills(int d , int tank, vector<int> & stops) {
  
    int currentRefil = 0 ;//will store the index of gas station where the car is currently
    int lastRefil = 0 ;//will store the index of gas station where we last refiiled
    int numRefils = 0 ;//will store how many refils we have done

    int n = stops.size() ;

    // cout << n ;

    while (stops[currentRefil] < d ){

        // cout << endl ;

        lastRefil = currentRefil ;
        // cout<< "lastRefil are : " << lastRefil << endl ;
      
        while((currentRefil <= n-2 ) && ((stops[ currentRefil + 1 ] - stops[ lastRefil ]) <= tank )){
            
            currentRefil = currentRefil + 1 ;

             // cout << currentRefil << " : " ;

            }


        // cout<<endl;
        // cout << "currentRefil are : " << currentRefil <<endl;


        if( currentRefil == lastRefil ){
            return -1;//means impossible to travel from intial to final
        }


        if(currentRefil <= n-2 ){
            numRefils = numRefils + 1 ;
        }
        
        
    }
    return numRefils ;
    
}


int main() {

    // d - distance between initial and final
    int d = 0;
    cin >> d;

    //m - distance that after one refil car can travel
    int m = 0;
    cin >> m;

    //n - number of gas stations
    int n = 0;
    cin >> n;

    vector<int> stops(n+2);//n+2 n - gas stations and + 2 - for intial and final point 
    stops[0] = 0 ;//initial
    stops[n+1] = d ;//final

    //storing distance of gas station from intial
    for (int i = 1; i <= n; i++)
        cin >> stops[i];

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}


/*
Sample Test Case : 

Input :
950
400
4
200 375 550 750

Output :
2

Explanation :
The distance between the cities is 950, the car can travel at most 400 miles on a full tank. It suffices
to make two refills: at points 375 and 750. This is the minimum number of refills as with a single refill
one would only be able to travel at most 800 miles.

*/