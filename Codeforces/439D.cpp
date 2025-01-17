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

const int INF = 0x3F3F3F3F3F3F3F3F;
int n, m, a[100005], b[100005];

int cal(int mid)
{
    int ret = 0, i;
    rep(i, n)
        if(a[i] < mid) ret += mid - a[i];
    rep(i, m)
        if(b[i] > mid) ret += b[i] - mid;
    return ret;
}

int dif(int mid)
{
    return cal(mid) - cal(mid - 1);
}

signed main()
{
    fastio;
    int i;
    cin >> n >> m;
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];
    int l = min(*min_element(a, a + n), *min_element(b, b + m)), r = max(*max_element(a, a + n), *max_element(b, b + m)) + 1;
    while(l < r - 1)
    {
        int mid = (l + r) / 2;
        if(dif(mid) < 0) l = mid;
        else r = mid;
    }
    cout << cal(l) << "\n";
}