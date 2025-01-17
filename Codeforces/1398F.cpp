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
#define lc 2 * id + 1
#define rc 2 * id + 2
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

int n, nxt[1000001];
vector<int> p[1000001];
string s;

int f(int pos, int x)
{
    if(nxt[pos] >= x)
        return pos + x;
    auto it = lower_bound(all(p[x]), pos);
    if(it == p[x].end())
        return n + 1;
    return *it + x;
}

signed main()
{
    fastio;
    int i, pos, cnt;
    cin >> n >> s;
    int l0 = n, l1 = n;
    oof(i, n - 1, 0)
    {
        if(s[i] == '0')
        {
            nxt[i] = l1 - i;
            l0 = i;
        }
        else if(s[i] == '1')
        {
            nxt[i] = l0 - i;
            l1 = i;
        }
        else
            nxt[i] = nxt[i + 1] + 1;
    }
    l0 = -1, l1 = -1;
    rep(i, n)
    {
        if(s[i] == '0')
        {
            p[i - l1].pb(l1 + 1);
            l0 = i;
        }
        else if(s[i] == '1')
        {
            p[i - l0].pb(l0 + 1);
            l1 = i;
        }
        else
        {
            p[i - l1].pb(l1 + 1);
            p[i - l0].pb(l0 + 1);
        }
    }
    cout << n << " \n"[n == 1];
    foo(i, 2, n)
    {
        pos = cnt = 0;
        while(1)
        {
            pos = f(pos, i);
            if(pos == n + 1) break;
            cnt++;
        }
        cout << cnt << " \n"[i == n];
    }
}