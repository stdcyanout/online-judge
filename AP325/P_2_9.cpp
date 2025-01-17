#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
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
using namespace __gnu_pbds;
using namespace std;

gp_hash_table<int, int> h;
int a[20], b[20], l[1 << 20], r[1 << 20], tmp[1 << 20];

int pw(int n, int k, int m)
{
    if(k == 0)
        return 1;
    int res = pw(n, k / 2, m);
    if(k & 1)
        return res * res % m * n % m;
    return res * res % m;
}

signed main()
{
    int n, p, i, j, cnt = 0;
    cin >> n >> p;
    rep(i, n / 2)
        cin >> a[i];
    rep(i, (n + 1) / 2)
        cin >> b[i];
    l[0] = 1;
    int lsz = 1;
    rep(i, n / 2)
    {
        rep(j, lsz)
            l[j + lsz] = (l[j] * a[i]) % p;
        lsz *= 2;
    }
    rep(i, lsz)
        ++h[l[i]];
    r[0] = 1;
    int rsz = 1;
    rep(i, (n + 1) / 2)
    {
        rep(j, rsz)
            r[j + rsz] = (r[j] * b[i]) % p;
        rsz *= 2;
    }
    rep(i, rsz)
        cnt += h[pw(r[i], p - 2, p)];
    cout << cnt - 1 << "\n";
}