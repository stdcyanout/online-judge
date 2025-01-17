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

int n, k, h[200005], w[5005];
vector<int> cont;

int cal(int mid)
{
    cont.clear();
    int i, j, cur = 0;
    rep(i, n)
    {
        if(h[i] >= mid)
            cur++;
        else
            if(cur) cont.pb(cur), cur = 0;
    }
    if(cur) cont.pb(cur), cur = 0;
    for(i = j = 0; j < cont.size();)
    {
        if(w[i] <= cont[j])
        {
            cont[j] -= w[i];
            i++;
            if(cont[j] <= 0) j++;
        }
        else
            j++;
        if(i == k) return 1;
    }
    return 0;
}

signed main()
{
    fastio;
    int i;
    cin >> n >> k;
    rep(i, n)
        cin >> h[i];
    rep(i, k)
        cin >> w[i];
    int l = 1, r = *max_element(h, h + n) + 1;
    while(l < r - 1)
    {
        int mid = (l + r) / 2;
        if(cal(mid))
            l = mid;
        else
            r = mid;
    }
    cout << l << "\n";
}