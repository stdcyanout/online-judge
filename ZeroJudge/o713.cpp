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

int cnttag = 1;
map<pii, int> tag;
vector<pii> explode[1505];
int a[505][505], vis[505][505];
int dr[] = {0, 1, 0, -1}, dc[] = {1, 0, -1, 0};

inline bool check(int r, int c)
{
    if(a[r][c] == -1)
        return 0;
    if(vis[r][c] & 1)
        return 0;
    return 1;
}

void init(int r, int c)
{
    int i;
    array<int, 3> p;
    queue<array<int, 3>> q;
    tag[{r, c}] = cnttag;
    q.push({r, c, a[r][c]});
    vis[r][c] = 1;
    while(!q.empty())
    {
        p = q.front();
        // debug(cnttag, p[0], p[1], p[2]);
        explode[cnttag].pb({p[0], p[1]});
        q.pop();
        rep(i, 4)
        {
            if(check(p[0] + dr[i], p[1] + dc[i]) && p[2] > 0)
            {
                vis[p[0] + dr[i]][p[1] + dc[i]] = 1;
                q.push({p[0] + dr[i], p[1] + dc[i], p[2] - 1});
            }
        }
    }
    for(pii tmp : explode[cnttag])
        vis[tmp.F][tmp.S] = 0;
    cnttag++;
}

int cal(int r, int c, int m)
{
    memset(vis, 0, sizeof(vis));
    int i, cnt = 1, nd = 0;
    array<int, 3> p;
    queue<array<int, 3>> q;
    queue<int> wait;
    q.push({r, c, 0});
    vis[r][c] = 1;
    while(!q.empty())
    {
        if(cnt >= m)
            break;
        p = q.front();
        // debug(cnt, p[0], p[1], p[2]);
        q.pop();
        rep(i, 4)
        {
            if(check(p[0] + dr[i], p[1] + dc[i]))
            {
                vis[p[0] + dr[i]][p[1] + dc[i]] += 1;
                if(!(vis[p[0] + dr[i]][p[1] + dc[i]] & 2)) cnt++;
                int t = tag[{p[0] + dr[i], p[1] + dc[i]}];
                if(t) wait.push(t);
                q.push({p[0] + dr[i], p[1] + dc[i], p[2] + 1});
                nd = max(nd, p[2] + 1);
            }
        }
        while(!wait.empty())
        {
            for(pii tmp : explode[wait.front()])
            {
                if(!vis[tmp.F][tmp.S])
                {
                    vis[tmp.F][tmp.S] = 2;
                    cnt++;
                    int t = tag[tmp];
                    if(t) wait.push(t);
                }
            }
            wait.pop();
        }
    }
    return nd;
}

signed main()
{
    fastio;
    int n, m, q, i, j, r, c;
    cin >> n >> m >> q;
    // assert(n * m < 100000);
    foo(i, 1, n) foo(j, 1, m) 
        cin >> a[i][j];
    foo(i, 0, n + 1)
        a[i][0] = a[i][m + 1] = -1;
    foo(j, 0, m + 1)
        a[0][j] = a[n + 1][j] = -1;
    foo(i, 1, n) foo(j, 1, m)
    {
        if(a[i][j] == -2)
            r = i, c = j;
        if(a[i][j] > 0)
            init(i, j);
    }
    cout << cal(r, c, q) << "\n";
}