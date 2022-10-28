#include <iostream>
#include <algorithm>
#include <vector>

#define pii pair<int, int>
#define vii vector<pii>
#define ff first
#define ss second
#define pb push_back
#define rep(i,a,b) for(int i=a; i<b; i++)

using namespace std;

bool mysort(pii &a, pii &b){
	double d1 = (double) a.ff/a.ss;
	double d2 = (double) b.ff/b.ss;
	return d1>d2;
}
int getMaxValue(int val[], int weight[], int n, int w){
	vii v;
	rep(i,0,n){
		v.pb(make_pair(val[i], weight[i]));
	}
	sort(v.begin(), v.end(), mysort);

	int total_value=0;
	rep(i,0,n){
		if(w>=v[i].ss){
			w-=v[i].ss;
			total_value += v[i].ff;
			continue;
		}
		cout<<v[i].ff<<endl;
		double vw = (double) v[i].ff/v[i].ss;
		total_value += vw*w;
		w=0;  
		break;
	}
	return total_value;
}

int main(){
	int value[] = {60,100,120};
	int weight[] = {10,20,30};
	int n=3;
	int max_weight=50;
	cout<<getMaxValue(value, weight, n, max_weight);
	return 0;
}