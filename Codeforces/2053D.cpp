#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fastio ios_base::sync_with_stdio(false),cin.tie(0);
#define safe cerr << __PRETTY_FUNCTION__ << " line " << __LINE__ << " safe\n";
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
    (..., (cerr << args << (--cnt ? " " : "\n")));
}
template <class T> void orange(T L, T R)
{
    for (int f = 0; L != R; ++L) cerr << (f++ ? " " : "") << *L;
    cerr << "\n";
}

const int MOD = 998244353;
pii a[200005], b[200005];
int ta[200005], tb[200005];

int pw(int aa, int nn)
{
    if(nn == 0) return 1;
    int ret = pw(aa, nn / 2);
    if(nn & 1) return ret * ret % MOD * aa % MOD;
    return ret * ret % MOD;
}

void solve()
{
    int n, q, i, o, x, db, pp, qq, fx;
    cin >> n >> q;
    rep(i, n) cin >> a[i].F, a[i].S = i;
    rep(i, n) cin >> b[i].F, b[i].S = i;
    sort(a, a + n);
    sort(b, b + n);
    rep(i, n)
        ta[a[i].S] = tb[b[i].S] = i;
    int p = 1;
    rep(i, n) p = (p * min(a[i].F, b[i].F)) % MOD;
    cout << p << " ";
    // 
    //
    while(q--)
    {
        cin >> o >> x;
        x--;
        db = 0;
        if(o == 1)
        {
            x = ta[x];
            pp = min(a[x].F, b[x].F);
            a[x].F++;
            if(x != n - 1 && a[x].F > a[x + 1].F)
            {
                db = 1;
                fx = lower_bound(a + x + 1, a + n, mp(a[x].F, int(0))) - a;
                fx--;
                qq = min(a[fx].F, b[fx].F);
                swap(ta[a[x].S], ta[a[fx].S]);
                swap(a[x], a[fx]);
            }
        }
        else
        {
            x = tb[x];
            pp = min(a[x].F, b[x].F);
            b[x].F++;
            if(x != n - 1 && b[x].F > b[x + 1].F)
            {
                db = 1;
                fx = lower_bound(b + x + 1, b + n, mp(b[x].F, int(0))) - b;
                fx--;
                qq = min(a[fx].F, b[fx].F);
                swap(tb[b[x].S], tb[b[fx].S]);
                swap(b[x], b[fx]);
            }
        }
        p = p * pw(pp, MOD - 2) % MOD;
        if(db) p = p * pw(qq, MOD - 2) % MOD;
        pp = min(a[x].F, b[x].F);
        if(db) qq = min(a[fx].F, b[fx].F);
        p = p * pp % MOD;
        if(db) p = p * qq % MOD;
        cout << p << " \n"[q == 0];
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
        solve();
}