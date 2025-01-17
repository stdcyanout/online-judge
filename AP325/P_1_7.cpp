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

const int MOD = 10009;
int n, a[30], cnt = 0;

void solve(int k, int t)
{
    if(k == n)
    {
        if(t % MOD == 1)
            ++cnt;
        return;
    }
    solve(k + 1, t);
    solve(k + 1, t * a[k] % MOD);
}

signed main()
{
    int i;
    cin >> n;
    rep(i, n)
        cin >> a[i];
    solve(0, 1);
    cout << cnt - 1 << "\n";
}