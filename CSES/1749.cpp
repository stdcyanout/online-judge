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

int a[200001], seg[800005];

void pull(int id)
{
    seg[id] = seg[lc] + seg[rc];
}

void build(int L, int R, int id)
{
    if(L == R - 1)
    {
        seg[id] = 1;
        return;
    }
    int M = (L + R) / 2;
    build(L, M, lc);
    build(M, R, rc);
    pull(id);
}

void update(int L, int R, int id, int pos)
{
    if(L == R - 1)
    {
        seg[id] = 0;
        return;
    }
    int M = (L + R) / 2;
    if(pos < M)
        update(L, M, lc, pos);
    else
        update(M, R, rc, pos);
    pull(id);
}

int query(int L, int R, int id, int val)
{
    if(L == R - 1)
        return L;
    int M = (L + R) / 2;
    if(seg[lc] >= val)
        return query(L, M, lc, val);
    else
        return query(M, R, rc, val - seg[lc]);
}

signed main()
{
    fastio;
    int n, i, p, pos;
    cin >> n;
    build(0, n, 0);
    rep(i, n)
        cin >> a[i];
    rep(i, n)
    {
        cin >> p;
        pos = query(0, n, 0, p);
        cout << a[pos] << " \n"[i == n - 1];
        update(0, n, 0, pos);
    }
}