#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fastio ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
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
    for (int f = 0; L != R; ++L) cout << (f++ ? " " : "") << *L;
    cout << "\n";
}

signed main()
{
    fastio;
    int t,n,k,tmp,i;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        tmp=k-1;
        vector<int> v;
        for(i=1;i<=tmp;tmp-=i,i*=2)
            v.pb(i);
        if(tmp) v.pb(tmp);
        v.pb(2*k+1);
        cout << 25 << "\n";
        for(i=k+1;v.size()<25;i*=2)
            v.pb(i);
        orange(all(v));
    }
}