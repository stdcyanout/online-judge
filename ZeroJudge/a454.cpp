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

vector<int> graph[1001];
int in[1001], d[1001], dp[1001];

void solve()
{
    int n, i, t, v, node;
    memset(dp, 0, sizeof(dp));
    cin >> n;
    foo(i, 1, n)
    {
        graph[i].clear();
        cin >> d[i] >> t;
        while(t--)
        {
            cin >> v;
            graph[i].pb(v);
            in[v]++;
        }
    }
    queue<int> q;
    foo(i, 1, n)
        if(in[i] == 0)
            q.push(i), dp[i] = d[i];
    while(!q.empty())
    {
        node = q.front();
        q.pop();
        for(int p : graph[node])
        {
            in[p]--;
            dp[p] = max(dp[p], dp[node] + d[p]);
            if(in[p] == 0) q.push(p);
        }
    }
    cout << *max_element(dp + 1, dp + n + 1) << "\n";
}

signed main()
{
    fastio;
    int t;
    cin >> t;
    while(t--)
        solve();
}