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
int tag[1001], cnttag;
int w[1001], b[1001], ww[1001], bb[1001], anc[1001], sz[1001];
vector<vector<int>> dw, db;
int dp[1001][1001];

int find(int i)
{
    if(anc[i] == i) return i;
    return anc[i] = find(anc[i]);
}

signed main()
{
    fastio;
    int n, m, W, x, y, t, i, j, k;
    cin >> n >> m >> W;
    memset(tag, 0x3F, sizeof(tag));
    foo(i, 1, n) cin >> w[i], ww[i] = w[i];
    foo(i, 1, n) cin >> b[i], bb[i] = b[i];
    foo(i, 1, n)
    {
        anc[i] = i;
        sz[i] = 1;
    }
    while(m--)
    {
        cin >> x >> y;
        x = find(x), y = find(y);
        if(x != y)
        {
            if(sz[x] < sz[y])
                swap(x, y);
            anc[y] = x;
            sz[x] += sz[y];
            ww[x] += ww[y];
            bb[x] += bb[y];
        }
    }
    foo(i, 1, n)
    {
        if(i == find(i))
            tag[i] = cnttag++;
    }
    dw.resize(cnttag);
    db.resize(cnttag);
    foo(i, 1, n)
    {
        t = find(i);
        if(i == t)
        {
            dw[tag[i]].pb(ww[i]);
            db[tag[i]].pb(bb[i]);
        }
        dw[tag[t]].pb(w[i]);
        db[tag[t]].pb(b[i]);
    }
    foo(i, 1, cnttag)
    {
        rep(j, dw[i - 1].size())
        {
            oof(k, W, dw[i - 1][j])
                dp[i][k] = max({dp[i - 1][k], dp[i][k], dp[i - 1][k - dw[i - 1][j]] + db[i - 1][j]});
            rep(k, dw[i - 1][j])
                dp[i][k] = max(dp[i - 1][k], dp[i][k]);
        }
    }
    cout << dp[cnttag][W] << "\n";
}