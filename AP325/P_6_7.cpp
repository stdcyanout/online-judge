#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define int int64_t
#define double long double
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define rep(i,n) for(i=0;i<(n);++i)
#define foo(i,a,b) for(i=(a);i<=(b);++i)
#define oof(i,a,b) for(i=(a);i>=(b);--i)
#define all(x) begin(x),end(x)
using namespace std;

vector<int> alpha[128], v, dp;

signed main()
{
    string s, t;
    int i;
    cin >> s >> t;
    oof(i, s.length() - 1, 0)
        alpha[int(s[i])].pb(i);
    rep(i, t.length())
        for(int j : alpha[int(t[i])])
            v.pb(j);
    rep(i, v.size())
    {
        if(dp.empty() || dp.back() < v[i])
            dp.pb(v[i]);
        else
            *lower_bound(all(dp), v[i]) = v[i];
    }
    cout << dp.size() << "\n";
}