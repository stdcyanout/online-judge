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

int anc[200001][20], dep[200001], vis[200001];
vector<int> graph[200001];

void dfs(int n)
{
    vis[n] = 1;
    int i;
    dep[n] = dep[anc[n][0]] + 1;
    foo(i, 1, 18) anc[n][i] = anc[anc[n][i - 1]][i - 1];
    for(int t : graph[n])
    {
        if(!vis[t])
            anc[t][0] = n, dfs(t);
    }
}

int lca(int a, int b)
{
    if(dep[a] < dep[b])
        swap(a, b);
    int tmp = dep[a] - dep[b], i;
    for(i = 0; tmp; i++, tmp >>= 1)
        if(tmp & 1) a = anc[a][i];
    if(a == b) return a;
    oof(i, 18, 0)
        if(anc[a][i] != anc[b][i])
            a = anc[a][i], b = anc[b][i];
    return anc[a][0];
}

signed main()
{
    fastio;
    int n, q, a, b, i;
    cin >> n >> q;
    rep(i, n - 1)
    {
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    anc[1][0] = 1;
    dfs(1);
    while(q--)
    {
        cin >> a >> b;
        cout << dep[a] + dep[b] - 2 * dep[lca(a, b)] << "\n";
    }
}