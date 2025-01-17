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
#define lowbit(x) (x & -(x))
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

int n, a[1001][1001], bit[1001][1001];

void update(int y, int x, int val)
{
    int i, j;
    for(i = y; i <= n; i += lowbit(i))
        for(j = x; j <= n; j += lowbit(j))
            bit[i][j] += val;
}

int query(int y, int x)
{
    int i, j, res = 0;
    for(i = y; i > 0; i -= lowbit(i))
        for(j = x; j > 0; j -= lowbit(j))
            res += bit[i][j];
    return res;
}

signed main()
{
    fastio;
    int q, t, y1, x1, y2, x2, i, j;
    char c;
    cin >> n >> q;
    foo(i, 1, n) foo(j, 1, n)
    {
        cin >> c;
        if(c == '*')
        {
            a[i][j] = 1;
            update(i, j, 1);
        }
    }
    while(q--)
    {
        cin >> t;
        if(t == 1)
        {
            cin >> y1 >> x1;
            if(a[y1][x1] == 1)
            {
                update(y1, x1, -1);
                a[y1][x1] = 0;
            }
            else
            {
                update(y1, x1, 1);
                a[y1][x1] = 1;
            }
        }
        else
        {
            cin >> y1 >> x1 >> y2 >> x2;
            cout << query(y2, x2) - query(y2, x1 - 1) - query(y1 - 1, x2) + query(y1 - 1, x1 - 1) << "\n";
        }
    }
}