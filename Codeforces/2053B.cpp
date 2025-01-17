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

int l[200005], r[200005];
vector<int> v;
multiset<int> s;

void solve()
{
    v.clear();
    s.clear();
    int n, i;
    cin >> n;
    rep(i, n) cin >> l[i] >> r[i];
    rep(i, n)
    {
        if(l[i] == r[i])
            v.pb(l[i]), s.insert(l[i]);
    }
    sort(all(v));
    v.erase(unique(all(v)), v.end());
    rep(i, n)
    {
        if(l[i] == r[i])
        {
            if(s.count(l[i]) > 1) cout << 0;
            else cout << 1;
        }
        else
        {    
            if(upper_bound(all(v), r[i]) - lower_bound(all(v), l[i]) == r[i] - l[i] + 1)
                cout << 0;
            else
                cout << 1;
        }
    }
    cout << "\n";
}

signed main()
{
    fastio;
    int t;
    cin >> t;
    while(t--)
        solve();
}