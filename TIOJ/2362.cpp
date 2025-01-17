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

vector<pii> v;

signed main()
{
    fastio;
    int m, n, t, k, r, c, i, cnt = 0, tmp, u, d, sz;
    cin >> m >> n >> t >> k >> r;
    u = max(int(1), r - k + 1);
    d = min(m - k + 1, r);
    sz = max(int(0), d - u + 1);
    rep(i, t)
    {
        cin >> c;
        v.pb(mp(max(int(1), c - k + 1), 1));
        v.pb(mp(min(n - k + 2, c + 1), -1));
    }
    sort(all(v));
    v.pb(mp(n - k + 2, 0));
    rep(i, v.size())
    {
        if(v[i].F == n - k + 2)
            break;
        tmp += v[i].S;
        if(tmp & 1)
            cnt += (v[i + 1].F - v[i].F) * sz;
    }
    if(k & 1)
        cnt = (m - k + 1) * (n - k + 1) - cnt;
    cout << cnt << "\n";
}