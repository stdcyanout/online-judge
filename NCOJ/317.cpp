#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false),cin.tie(0);
#define int int64_t
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define rep(i,n) for(i = 0; i < (n); i++)
#define foo(i,a,b) for(i = (a); i <= (b); i++)
#define oof(i,a,b) for(i = (a); i >= (b); i--)
#define all(x) x.begin(),x.end()
using namespace std;

vector<pii> graph[100001];
vector<int> ans;
int a[100001], vis[100001], press[200001];

int dfs(int e, int n)
{
    vis[n] = 1;
    int ans = 0;
    for(pii p: graph[n])
    {
        if(!vis[p.F])
            ans += dfs(p.S, p.F);
    }
    return press[e] = (ans & 1) ^ a[n];
}

signed main()
{
    fastio;
    int n, m, i, x, y, s;
    cin >> n >> m;
    foo(i, 1, n)
        cin >> a[i];
    foo(i, 1, m)
    {
        cin >> x >> y;
        graph[x].pb(mp(y, i));
        graph[y].pb(mp(x, i));
    }
    foo(i, 1, n)
    {
        if(!vis[i])
        {
            s = dfs(0, i);
            if(s)
            {
                cout << "No\n";
                return 0;
            }
        }
    }
    cout << "Yes\n";
    foo(i, 1, m)
    {
        if(press[i])
            ans.pb(i);
    }
    cout << ans.size() << "\n";
    rep(i, ans.size())
        cout << ans[i] << " \n"[i == ans.size() - 1];
}