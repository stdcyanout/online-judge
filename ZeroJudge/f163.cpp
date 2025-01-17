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

int w[2000005], item[10005], lc[2000005], rc[2000005];

void pull(int id)
{
    w[id] = w[lc[id]] + w[rc[id]];
}

void build(int id)
{
    if(lc[id] == 0 && rc[id] == 0)
        return;
    build(lc[id]);
    build(rc[id]);
    pull(id);
}

void update(int id, int val)
{
    if(lc[id] == 0 && rc[id] == 0)
    {
        cout << id;
        w[id] += val;
        return;
    }
    if(w[lc[id]] > w[rc[id]])
        update(rc[id], val);
    else
        update(lc[id], val);
    pull(id);
}

signed main()
{
    fastio;
    int n, m, i, a, b, c;
    cin >> n >> m;
    foo(i, n, 2 * n - 1)
        cin >> w[i];
    rep(i, m)
        cin >> item[i];
    rep(i, n - 1)
    {
        cin >> a >> b >> c;
        lc[a] = b, rc[a] = c;
    }
    build(1);
    rep(i, m)
    {
        update(1, item[i]);
        cout << " \n"[i == m - 1];
    }
}