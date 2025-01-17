#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fastio ios_base::sync_with_stdio(false),cin.tie(0);
#define safe cerr << __PRETTY_FUNCTION__ << " line " << __LINE__ << " safe\n";
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
    (..., (cerr << args << (--cnt ? " " : "\n")));
}
template <class T> void orange(T L, T R)
{
    for (int f = 0; L != R; ++L) cerr << (f++ ? " " : "") << *L;
    cerr << "\n";
}

void solve()
{
    int n, a, b, c, ret = 0;
    cin >> n >> a >> b >> c;
    ret += n / (a + b + c) * 3;
    n %= (a + b + c);
    if(n > 0) n -= a, ret++;
    if(n > 0) n -= b, ret++;
    if(n > 0) n -= c, ret++;
    cout << ret << "\n";
}

signed main()
{
    fastio;
    int t;
    cin >> t;
    while(t--)
        solve();
}