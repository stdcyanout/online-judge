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

int a[1005][1005], vis[1005][1005], back[1005][1005];
int dr[] = {0, 1, 0, -1}, dc[] = {1, 0, -1, 0}, r[] = {2, 3, 0, 1};
char d[] = {'R', 'D', 'L', 'U'};
string ans;

inline bool check(int r, int c)
{
    if(a[r][c] == 0) return false;
    if(vis[r][c] == 1) return false;
    return true;
}

void bfs(pii s, pii e)
{
    int i;
    queue<array<int, 3>> q;
    array<int, 3> node;
    q.push({s.F, s.S, 0});
    vis[s.F][s.S] = 1;
    while(!q.empty())
    {
        node = q.front();
        q.pop();
        if(node[0] == e.F && node[1] == e.S)
        {
            cout << "YES\n" << node[2] << "\n";
            while(e != s)
            {
                ans += d[back[e.F][e.S]];
                e = {e.F + dr[r[back[e.F][e.S]]], e.S + dc[r[back[e.F][e.S]]]};
            }
            oof(i, ans.length() - 1, 0) cout << ans[i];
            cout << "\n";
            return;
        }
        rep(i, 4)
        {
            if(check(node[0] + dr[i], node[1] + dc[i]))
            {
                q.push({node[0] + dr[i], node[1] + dc[i], node[2] + 1});
                vis[node[0] + dr[i]][node[1] + dc[i]] = 1;
                back[node[0] + dr[i]][node[1] + dc[i]] = i;
            }
        }
    }
    cout << "NO\n";
}

signed main()
{
    fastio;
    int n, m, i, j;
    pii s, e;
    char c;
    cin >> n >> m;
    foo(i, 1, n)
    {
        foo(j, 1, m)
        {
            cin >> c;
            if(c != '#')
                a[i][j] = 1;
            if(c == 'A')
                s = {i, j};
            if(c == 'B')
                e = {i, j};
        }
    }
    bfs(s, e);
}