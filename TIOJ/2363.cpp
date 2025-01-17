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

int a[300005], s[300005];
vector<pair<vector<int>, int>> dp;
vector<int> ans;

bool cmp(const pair<vector<int>, int>& a, int t, const pair<vector<int>, int>& b)
{
    int n = a.F.size(), i;
    rep(i, n)
    {
        if(a.F[i] + (i == t) > b.F[i])
            return 1;
        else if(a.F[i] + (i == t) < b.F[i])
            return 0;
    }
    return 0;
}

signed main()
{
    fastio;
    int n, k, e, i, j, p, tmp;
    cin >> n >> k >> e;
    rep(i, n)
    {
        cin >> tmp;
        a[tmp] = 1;
    }
    rep(i, k)
        cin >> s[i];
    sort(s, s + k, greater<int>());
    dp.resize(e + 1);
    rep(i, e + 1)
    {
        if(!a[i]) dp[i].F.resize(k);
        dp[i].S = -1;
    }
    dp[0].S = 0;
    foo(i, 1, e)
    {
        if(a[i]) continue;
        rep(j, k)
        {
            if(i - s[j] < 0 || dp[i - s[j]].S == -1) continue;
            if(cmp(dp[i - s[j]], j, dp[i]))
            {
                rep(p, k)
                    dp[i].F[p] = dp[i - s[j]].F[p] + (p == j);
                dp[i].S = i - s[j];
            }
        }
    }
    if(dp[e].S == -1)
    {
        cout << -1 << "\n";
        return 0;
    }
    tmp = e;
    while(tmp)
    {
        ans.pb(tmp);
        tmp = dp[tmp].S;
    }
    cout << ans.size() << "\n";
    oof(i, ans.size() - 1, 0)
        cout << ans[i] << " \n"[i == 0];
}