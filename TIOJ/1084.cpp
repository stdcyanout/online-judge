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

int vis[1025];
vector<pii> graph[501];
vector<int> ans;

void dfs(int n)
{
    sort(all(graph[n]));
    for(pii t : graph[n])
    {
        if(!vis[t.S])
            vis[t.S] = 1, dfs(t.F);
    }
    ans.pb(n);
}

signed main()
{
    fastio;
    int m, u, v, i;
    while(cin >> m && m)
    {
        foo(i, 1, 500) graph[i].clear();
        memset(vis, 0, sizeof(vis));
        ans.clear();
        rep(i, m)
        {
            cin >> u >> v;
            graph[u].pb({v, i});
            graph[v].pb({u, i});
        }
        foo(i, 1, 500)
        {
            if(graph[i].size() & 1)
            {
                dfs(i);
                break;
            }
        }
        if(i == 501)
        {
            foo(i, 1, 500)
            {
                if(!graph[i].empty())
                {
                    dfs(i);
                    break;
                }
            }
        }
        reverse(all(ans));
        for(int t : ans) cout << t << "\n";
        cout << "\n";
    }
}