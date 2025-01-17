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

const int INF = 0x3F3F3F3F3F3F3F3F;
vector<int> graph[1000005];
int a[1000005], vis[1000005];

int bfs(int s, int e)
{
    queue<pii> q;
    pii p;
    q.push({s, 0});
    vis[s] = 1;
    while(!q.empty())
    {
        p = q.front();
        q.pop();
        if(p.F == e)
            return p.S;
        for(int t : graph[p.F])
        {
            if(!vis[t])
            {
                vis[t] = 1;
                q.push({t, p.S + 1});
            }
        }
    }
    return INF;
}

signed main()
{
    fastio;
    int n, p, L, R, i;
    cin >> n >> p >> L >> R;
    rep(i, n) cin >> a[i];
    rep(i, n)
    {
        if(btw(0, i - L, n - 1))
            graph[i].pb(a[i - L]);
        if(btw(0, i + R, n - 1))
            graph[i].pb(a[i + R]);
    }
    int d = bfs(0, p);
    if(d == INF)
        cout << -1 << "\n";
    else
        cout << d << "\n";
}