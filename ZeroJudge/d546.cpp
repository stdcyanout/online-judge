#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fastio ios_base::sync_with_stdio(false),cin.tie(0);
#define safe cerr << "\e[1;31m" << __PRETTY_FUNCTION__ << " line " << __LINE__ << " safe\e[0m\n";
#define int int64_t
#define pii pair<int,int>
#define X first
#define Y second
#define mp make_pair
#define pb emplace_back
#define rep(i,n) for(i=0;i<(n);++i)
#define foo(i,a,b) for(i=(a);i<=(b);++i)
#define oof(i,a,b) for(i=(a);i>=(b);--i)
#define all(x) begin(x),end(x)
#define btw(a,b,c) ((a)<=(b)&&(b)<=(c))
#define eps 1e-9
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

vector<pii> v,hull;

pii operator-(pii a, pii b)
{
    return mp(a.X - b.X, a.Y - b.Y);
}
int operator^(pii a, pii b)
{
    return a.X * b.Y - a.Y * b.X;
}

signed main()
{
    fastio;
    int n,k,i,ans;
    double varea = 0,harea = 0;
    cin >> n >> k;
    v.resize(n);
    rep(i,n) cin >> v[i].X >> v[i].Y;
    rep(i,n)
        varea += v[i] ^ v[(i + 1) % n];
    varea = abs(varea) * 0.5;
    sort(all(v));
    rep(i,2)
    {
        int t = hull.size();
        for(pii p:v)
        {
            while(hull.size() - t >= 2 && ((hull.back() - hull[hull.size() - 2]) ^ (p - hull[hull.size() - 2])) <= 0)
                hull.pop_back();
            hull.pb(p);
        }
        hull.pop_back();
        reverse(all(v));
    }
    rep(i,hull.size())
        harea += hull[i] ^ hull[(i + 1) % hull.size()];
    harea = abs(harea) * 0.5;
    ans = ceil((harea - varea - eps) / k);
    cout << ans << "\n";
}