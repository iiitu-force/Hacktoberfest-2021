#include <iostream>
#include <vector>
#include<algorithm>

using namespace std ;

bool compare (  pair < double , double > a ,  pair < double , double > b ){
  return a.first > b.first ;
}

double get_optimal_value(double capacity, vector<double> weights, vector<int> values ) {
    
     //net value after fitting full capacity
    double value = 0.0;

    //storing the size for making vector
    int n = values.size();

    //vector for containig perUnit value a
    vector<double> perUnit(n);
   
    //vector for containing pair of wieght and corrospoding perunit value
    vector< pair < double , double > > v(n) ;

    //storing the data into vector having pair as element
    for (int i = 0; i < n; i++) {
      perUnit[i] =  values[i]/weights[i] ;
      
      v[i].first = perUnit[i];
      v[i].second = weights[i];

    }
     
    //storing the vector on the basis of perUnit value ie first value in pair
    sort( v.begin() , v.end()  , compare);

    //This is to print out data in the pair of sorted vector v 
    // for(pair < double , double >  x : v ){
    //  cout  << x.first << "," << x.second << endl ;
    // }

    //cout << endl ;

    for(int i = 0 ; i < n ; i++ ){
      if(capacity == 0 ){
        break ;
      }
      auto amount =  v[i].second > capacity ? capacity : v[i].second  ;
      // cout << amount << endl ;
      value = value + amount*v[i].first;
      capacity = capacity - amount ;
    }


    


    // write your code here

    return value;
}

int main() {

  int n ;

  double capacity;

  cin >> n >> capacity;

  vector<int> values(n);

  vector<double> weights(n);

  for (int i = 0; i < n; i++) {
    cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  cout.precision(10);

  cout << optimal_value << endl;
   return 0;
 }
