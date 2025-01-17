#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define int int64_t
#define double long double
#define pii pair<int,int>
#define X first
#define Y second
#define mp make_pair
#define rep(i,n) for(i=0;i<(n);++i)
#define all(x) begin(x),end(x)
using namespace std;

int a[100001], tmp[100001];

signed main()
{
    fastio;
    int n, sz, i;
    cin >> n;
    rep(i, n)
    {
        cin >> a[i];
        tmp[i] = a[i];
    }
    sort(tmp, tmp + n);
    sz = unique(tmp, tmp + n) - tmp;
    rep(i, n)
    {
        a[i] = lower_bound(tmp, tmp + sz, a[i]) - tmp;
        cout << a[i] << " \n"[i == n - 1];
    }
}