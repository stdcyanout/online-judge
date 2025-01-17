#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fastio ios_base::sync_with_stdio(false),cin.tie(0);
#define safe cerr << "\e[1;31m" << __PRETTY_FUNCTION__ << " line " << __LINE__ << " safe\e[0m\n";
#define int int64_t
#define pdd pair<long double,long double>
#define F first
#define S second
#define mp make_pair
#define pb push_back
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

vector<pdd> v;

signed main()
{
    fastio;
    int n, i;
    long double sx, sy, x1, x2, y;
    cin >> n >> sx >> sy;
    rep(i, n)
    {
        cin >> x1 >> x2 >> y;
        v.pb({(x1 - sx) / (sy - y) * sy, (x2 - sx) / (sy - y) * sy});
    }
    sort(all(v));
    long double l = -1e19, r = -1e19, len = 0;
    for(pdd p : v)
    {
        if(p.F <= r)
            r = max(r, p.S);
        else
        {
            len += r - l;
            l = p.F;
            r = p.S;
        }
    }
    len += r - l;
    cout << fixed << setprecision(12) << len << '\n';
}