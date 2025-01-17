#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fastio ios_base::sync_with_stdio(false),cin.tie(0);
#define safe cerr << "\e[1;31m" << __PRETTY_FUNCTION__ << " line " << __LINE__ << " safe\e[0m\n";
#define int int64_t
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define rep(i,n) for(i=0;i<(n);++i)
#define foo(i,a,b) for(i=(a);i<=(b);++i)
#define oof(i,a,b) for(i=(a);i>=(b);--i)
#define all(x) begin(x),end(x)
#define btw(a,b,c) ((a)<=(b)&&(b)<=(c))
using namespace __gnu_pbds;
using namespace std;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

template <class ...T> void debug(T ...args)
{
    int cnt = sizeof...(T);
    ((cerr << "\e[1;31m"), ..., (cerr << args << (--cnt ? " " : "\e[0m\n")));
}
template <class T> void orange(T L, T R)
{
    cerr << "\e[1;31m";
    for (int f = 0; L != R; ++L) cerr << (f++ ? " " : "") << *L;
    cerr << "\e[0m\n";
}

int dp[101][101][101];

signed main()
{
    fastio;
    string s,t,u;
    int i,j,k;
    cin >> s >> t >> u;
    foo(i,1,s.length())
    {
        foo(j,1,t.length())
        {
            foo(k,1,u.length())
            {
                if(s[i-1]==t[j-1]&&t[j-1]==u[k-1])
                    dp[i][j][k]=dp[i-1][j-1][k-1]+1;
                else
                    dp[i][j][k]=max({dp[i-1][j][k],dp[i][j-1][k],dp[i][j][k-1],dp[i-1][j-1][k],dp[i-1][j][k-1],dp[i][j-1][k-1]});
            }
        }
    }
    cout << dp[s.length()][t.length()][u.length()] << "\n";
}