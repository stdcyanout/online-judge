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

int n, m;
int a[201], lmin[201], rmin[201];

int mq()
{
    int i;
    stack<int> sl,sr;
    rep(i, m)
    {
        while(!sl.empty()&&a[sl.top()]>=a[i])
            sl.pop();
        if(!sl.empty())
            lmin[i]=sl.top();
        else
            lmin[i]=-1;
        sl.push(i);
    }
    oof(i, m - 1, 0)
    {
        while(!sr.empty()&&a[sr.top()]>=a[i])
            sr.pop();
        if(!sr.empty())
            rmin[i]=sr.top();
        else
            rmin[i]=m;
        sr.push(i);
    }
    int ma=0;
    rep(i, m)
    {
        ma=max(ma,(rmin[i]-lmin[i]-1)*a[i]);
    }
    return ma;
}

void solve()
{
    memset(a, 0, sizeof(a));
    int i, j, t, ma = 0;
    rep(i, n)
    {
        rep(j, m)
        {
            cin >> t;
            if(t == 0) a[j] = 0;
            else a[j]++;
        }
        ma = max(ma, mq());
    }
    cout << ma << "\n";
}

signed main()
{
    fastio;
    while(cin >> n >> m)
        solve();
}