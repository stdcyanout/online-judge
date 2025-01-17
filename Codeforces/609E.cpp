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
#define pb push_back
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

vector<pii> tr[200001];
int anc[200001], dep[200001], ancestor[200001][20], maxw[200001][20], sz[200001], inmst[200001], vis[200001], ans[200001];
array<int, 4> edge[200001];

bool cmp(const array<int, 4>& a, const array<int, 4>& b)
{
    return a[3] < b[3];
}

int find(int i)
{
    if(anc[i] == i) return i;
    return anc[i] = find(anc[i]);
}

void dfs(int n)
{
    vis[n] = 1;
    dep[n] = dep[ancestor[n][0]] + 1;
    int i;
    foo(i, 1, 18) ancestor[n][i] = ancestor[ancestor[n][i - 1]][i - 1], maxw[n][i] = max(maxw[n][i - 1], maxw[ancestor[n][i - 1]][i - 1]);
    for(pii t : tr[n]) if(!vis[t.F]) ancestor[t.F][0] = n, maxw[t.F][0] = t.S, dfs(t.F); 
}

int query(int a, int b)
{
    if(dep[a] < dep[b]) swap(a, b);
    int i, tmp, m1 = 0, m2 = 0;
    for(i = 0, tmp = dep[a] - dep[b]; tmp; i++, tmp >>= 1)
        if(tmp & 1) m1 = max(m1, maxw[a][i]), a = ancestor[a][i];
    if(a == b) return m1;
    oof(i, 18, 0)
        if(ancestor[a][i] != ancestor[b][i]) m1 = max(m1, maxw[a][i]), m2 = max(m2, maxw[b][i]), a = ancestor[a][i], b = ancestor[b][i];
    m1 = max(m1, maxw[a][0]), m2 = max(m2, maxw[b][0]);
    return max(m1, m2);
}

signed main()
{
    fastio;
    int n, m, a, b, i, w = 0;
    cin >> n >> m;
    rep(i, m) edge[i][0] = i, cin >> edge[i][1] >> edge[i][2] >> edge[i][3];
    sort(edge, edge + m, cmp);
    rep(i, n) anc[i] = i, sz[i] = 1;
    rep(i, m)
    {
        a = find(edge[i][1]), b = find(edge[i][2]);
        if(a != b)
        {
            w += edge[i][3];
            inmst[edge[i][0]] = 1;
            tr[edge[i][1]].pb({edge[i][2], edge[i][3]});
            tr[edge[i][2]].pb({edge[i][1], edge[i][3]});
            if(sz[a] < sz[b]) swap(a, b);
            anc[b] = a;
            sz[a] += sz[b];
        }
    }
    ancestor[1][0] = 1;
    dfs(1);
    rep(i, m)
    {
        if(inmst[edge[i][0]]) ans[edge[i][0]] = w;
        else ans[edge[i][0]] = w - query(edge[i][1], edge[i][2]) + edge[i][3];
    }
    rep(i, m) cout << ans[i] << "\n";
}