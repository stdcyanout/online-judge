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

int dis[100001];
vector<pii> graph[100001];
priority_queue<pii, vector<pii>, greater<pii>> pq;

signed main()
{
    fastio;
    int n, m, u, v, w, i;
    cin >> n >> m;
    while(m--)
    {
        cin >> u >> v >> w;
        graph[u].pb({v, w});
    }
    memset(dis, 0x3F, sizeof(dis));
    dis[1] = 0;
    pq.push({0, 1});
    while(!pq.empty())
    {
        pii p = pq.top();
        pq.pop();
        if(dis[p.S] < p.F)
            continue;
        for(pii t : graph[p.S])
        {
            if(p.F + t.S < dis[t.F])
            {
                dis[t.F] = p.F + t.S;
                pq.push({dis[t.F], t.F});
            }
        }
    }
    foo(i, 1, n) cout << dis[i] << " \n"[i == n];
}