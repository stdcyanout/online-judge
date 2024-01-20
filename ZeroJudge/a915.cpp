#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define RED "\e[1;31m"
#define RESET "\e[0m"
#define int long long
#define pii pair<int,int>
#define F first
#define S second

using namespace std;

void debug()
{
    cerr << "\n" << RESET;
}
template<class T,class ...U> void debug(T a,U ...b)
{
    cerr << RED << a << " ", debug(b...);
}

vector<pii> v;

signed main()
{
    fastIO
    int n;
    cin >> n;
    vector<pii> v(n);
    while(n--)
    {
        cin >> v[n].F >> v[n].S;
    }
    sort(v.begin(),v.end());
    for(pii p:v)
    {
        cout << p.F << " " << p.S << "\n";
    }
}