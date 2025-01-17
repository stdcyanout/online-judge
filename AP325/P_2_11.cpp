#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false),cin.tie(0);
#define int int64_t
#define pii pair<int, int>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define rep(i, n) for(i = 0; i < (n); ++i)
#define foo(i, a, b) for(i = (a); i <= (b); ++i)
#define oof(i, a, b) for(i = (a); i >= (b); --i)
#define all(x) x.begin(), x.end()
using namespace std;

set<int> s;
int a[100001];

signed main()
{
    int n, k, i, prefix = 0, ans = 0;
    cin >> n >> k;
    rep(i, n)
        cin >> a[i];
    s.insert(0);
    rep(i, n)
    {
        prefix += a[i];
        auto it = s.lower_bound(prefix - k);
        if(it != s.end())
            ans = max(ans, prefix - *it);
        s.insert(prefix);
    }
    cout << ans << "\n";
}