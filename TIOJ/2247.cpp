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
vector<int> graph[26];
string s[3] = {"QWERTYUIOP", "ASDFGHJKL", "ZXCVBNM"};
int vis[26], dis[26][26], w[10001], dp[10001][26][26];
queue<pii> q;

inline void joint(int n, int o, int t, int i)
{
    if(btw(0, i, s[t].length() - 1))
        graph[int(s[n][o] - 'A')].pb(int(s[t][i] - 'A'));
}

void bfs(int n)
{
    memset(vis, 0, sizeof(vis));
    q.push({n, 0});
    vis[n] = 1;
    while(!q.empty())
    {
        pii p = q.front();
        q.pop();
        dis[n][p.F] = p.S;
        for(int i : graph[p.F])
            if(!vis[i])
                q.push({i, p.S + 1}), vis[i] = 1;
    }
}

void init()
{
    int i;
    rep(i, s[0].length())
        joint(0, i, 0, i - 1), joint(0, i, 0, i + 1), joint(0, i, 1, i - 1), joint(0, i, 1, i);
    rep(i, s[1].length())
        joint(1, i, 0, i), joint(1, i, 0, i + 1), joint(1, i, 1, i - 1), joint(1, i, 1, i + 1), joint(1, i, 2, i - 1), joint(1, i, 2, i);
    rep(i, s[2].length())
        joint(2, i, 1, i), joint(2, i, 1, i + 1), joint(2, i, 2, i - 1), joint(2, i, 2, i + 1);
    memset(dis, 0x3F, sizeof(dis));
    rep(i, 26) bfs(i);
}

signed main()
{
    fastio;
    init();
    int n, i, j, k, ans = INF;
    char c;
    cin >> n;
    foo(i, 1, n)
        cin >> c, w[i] = int(c - 'A');
    memset(dp, 0x3F, sizeof(dp));
    dp[0][5][9] = 0;
    foo(i, 1, n)
    {
        rep(j, 26) rep(k, 26)
            dp[i][w[i]][j] = min(dp[i][w[i]][j], dp[i - 1][k][j] + dis[k][w[i]]);
        rep(j, 26) rep(k, 26)
            dp[i][j][w[i]] = min(dp[i][j][w[i]], dp[i - 1][j][k] + dis[k][w[i]]);
    }
    rep(i, 26) rep(j, 26)
        ans = min(ans, dp[n][i][j]);
    cout << ans << "\n";
}