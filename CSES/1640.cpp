#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pii pair<int,int>
#define mp make_pair
#define F first
#define S second
 
using namespace std;
 
int main()
{
    int n,x,i,t,l,r;
    vector<pii> v;
    cin >> n >> x;
    for(i=0;i<n;i++)
    {
        cin >> t;
        v.emplace_back(t,i+1);
    }
    
    sort(v.begin(),v.end());
    l=0;
    r=n-1;
    while(l<r)
    {
        if(v[l].F+v[r].F==x)
        {
            cout << v[l].S << " " << v[r].S << "\n";
            return 0;
        }
        if(v[l].F+v[r].F>x)
            r--;
        if(v[l].F+v[r].F<x)
            l++;
    }
    cout << "IMPOSSIBLE\n";
}