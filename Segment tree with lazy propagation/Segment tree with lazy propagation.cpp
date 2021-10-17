/*
     _/_/_/_/_/_/  _/_/_/_/_/  _/_/_/_/_/  _/_/_/_/_/  _/_/_/_/_/  _/   _/
      _/      _/  _/          _/          _/      _/  _/      _/  _/  _/
     _/      _/  _/_/_/      _/_/_/      _/_/_/_/_/  _/_/_/_/_/  _/_/
    _/      _/  _/          _/          _/          _/      _/  _/  _/
 _/_/_/_/_/_/  _/_/_/_/_/  _/_/_/_/_/  _/          _/      _/  _/    _/
*/

#include<bits/stdc++.h>
#include<math.h>
#define RED_BULL        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int             long long
#define test            int t; cin>>t; while(t--)
#define vi              vector<int>
#define vc              vector<char>
#define viip            vector< pair<int, int>>
#define vcip            vector< pair<char, int>>
#define pb              push_back
#define mp              make_pair
#define ff              first
#define ss              second
#define umap            unordered_map<int, int>
#define uset            unordered_set<int>  
#define Ceil(a, b)      (1 + (a - 1)/b)
#define lcm(a, b)       a*b/__gcd(a, b)
#define input(arr)      int n; cin>>n; int arr[n]; for(int i=0; i<n; i++) {cin>>arr[i];}
#define f(i, n)         for(int i=0; i<n; i++)
#define ff1(i, n)        for(int i=1; i<=n; i++)
#define f1(i, n)        for(int i=1; i<n; i++)
#define rf(i, n)        for(int i=n-1; i>=0; i--)
#define OK              if(ok){cout<<"YES"<<endl;} else{cout<<"NO"<<endl;}
#define Ok              if(ok){cout<<"Yes"<<endl;} else{cout<<"No"<<endl;}
#define mod             1000000007
#define endl "\n"
using namespace std;
//*************************************************************************************************

void build(int *tree, int *arr, int l, int r, int i)
{
    if(l > r)
        return;
    if(l == r)
    {
        tree[i] = arr[l];
        return;
    }

    int mid = (l + r) / 2;
    build(tree, arr, l, mid, 2*i);
    build(tree, arr, mid+1, r, 2*i+1);
    tree[i] = min(tree[2*i], tree[2*i+1]);
}

void update(int *tree, int *lazy, int l, int r, int i, int x, int y, int val)
{
    if(l > r)
        return;
    if(l > y  || r < x)
        return;
    if(lazy[i])
    {
        lazy[2*i] = lazy[2*i+1] = lazy[i];
        lazy[i] = 0;
    }
    if(l == r)
    {
        tree[i] += val;
        return; 
    }
    if(x <= l  and  r <= y)
    {
        lazy[i] += val;
        tree[i] += val;
        return;
    }

    int mid = (l + r) / 2;
    update(tree, lazy, l, mid, 2*i, x, y, val);
    update(tree, lazy, mid+1, r, 2*i+1, x, y, val);
    tree[i] = min(tree[2*i], tree[2*i+1]);
}

int segmentTree(int *tree, int l, int r, int i, int x, int y)
{
    if(l > r)
        return INT_MAX;
    if(l > y  || r < x)
        return INT_MAX;
    if(l == r)
        return tree[i];
    if(x <= l  and  r <= y)
        return tree[i];    

    int mid = (l + r) / 2;
    int left = segmentTree(tree, l, mid, 2*i, x, y);
    int right = segmentTree(tree, mid+1, r, 2*i+1, x, y);
    return min(left, right);
}

void solve()
{
    int n;
    cin >> n;
    int arr[n+1];
    ff1(i, n)
    {
        cin >> arr[i];
    }
    int tree[4*n+1];
    int lazy[4*n+1] = {0};

    build(tree, arr, 1, n, 1);
    
    int q;
    cin >> q;
    while(q--)
    {
        int a;
        cin >> a;
        int x, y, val;
        if(a == 0)
        {
            cin >> x >> y;
            cout << segmentTree(tree, 1, n, 1, x, y) << endl;
        }
        else
        {
            cin >> x >> y >> val;
            update(tree, lazy, 1, n, 1, x, y, val);
        }
    }
}

int32_t main()
{
    RED_BULL
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    //cin >> t; 
    while(t--)
    {
        solve();
    }
    return 0;
} 
