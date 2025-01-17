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
#define lc 2 * id + 1
#define rc 2 * id + 2
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

const int INF = 0x3F3F3F3F3F3F3F3F;

int arr[2000001], seg[2][8000005];

void pull(int id)
{
    seg[0][id] = min(seg[0][lc], seg[0][rc]);
    seg[1][id] = max(seg[1][lc], seg[1][rc]);
}

void build(int L, int R, int id)
{
    if(L == R - 1)
    {
        seg[0][id] = seg[1][id] = arr[L];
        return;
    }
    int M = (L + R) / 2;
    build(L, M, lc);
    build(M, R, rc);
    pull(id);
}

int query_min(int L, int R, int id, int l, int r)
{
    if(R <= l || r <= L)
        return INF;
    if(l <= L && R <= r)
        return seg[0][id];
    int M = (L + R) / 2;
    return min(query_min(L, M, lc, l, r), query_min(M, R, rc, l, r));
}

int query_max(int L, int R, int id, int l, int r)
{
    if(R <= l || r <= L)
        return -INF;
    if(l <= L && R <= r)
        return seg[1][id];
    int M = (L + R) / 2;
    return max(query_max(L, M, lc, l, r), query_max(M, R, rc, l, r));
}

signed main()
{
    fastio;
    int n, i, t = 0;
    cin >> n;
    rep(i, n)
    {
        cin >> arr[i];
        arr[n + i] = arr[i];
    }
    foo(i, 1, 2 * n - 1)
        arr[i] += arr[i - 1];
    build(0, 2 * n, 0);
    rep(i, n)
    {
        if(i) t = arr[i - 1];
        cout << min(int(0), query_min(0, 2 * n, 0, i, i + n) - t) << " " << max(int(0), query_max(0, 2 * n, 0, i, i + n) - t) << "\n";
    }
}