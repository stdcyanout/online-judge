// #pragma GCC optimize("O3,unroll-loops")
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

int n, block, cnt = 0;
int a[1000001], srt[1000001], belong[1000001], l[1001], r[1001], d[1001];

void init()
{
    int i, j;
    block = sqrt(n);
    for(i = 0;; i++)
    {
        cnt++;
        l[i] = i * block;
        r[i] = (i + 1) * block;
        if(r[i] > n)
        {
            r[i] = n;
            break;
        }
    }
    rep(i, cnt)
    {
        sort(srt + l[i], srt + r[i]);
        foo(j, l[i], r[i] - 1)
            belong[j] = i;
    }
}

void update(int L, int R, int val)
{
    int lb = belong[L], rb = belong[R - 1], i;
    if(lb == rb)
    {
        foo(i, L, R - 1)
            a[i] += val;
        copy(a + l[lb], a + r[lb], srt + l[lb]);
        sort(srt + l[lb], srt + r[lb]);
    }
    else
    {
        foo(i, L, r[lb] - 1)
            a[i] += val;
        foo(i, l[rb], R - 1)
            a[i] += val;
        copy(a + l[lb], a + r[lb], srt + l[lb]);
        sort(srt + l[lb], srt + r[lb]);
        copy(a + l[rb], a + r[rb], srt + l[rb]);
        sort(srt + l[rb], srt + r[rb]);
        lb += 1;
        rb -= 1;
        if(rb < lb)
            return;
        foo(i, lb, rb)
            d[i] += val;
    }
}

int query(int L, int R, int val)
{
    int lb = belong[L], rb = belong[R - 1], i, res = 0;
    if(lb == rb)
    {
        foo(i, L, R - 1)
            res += a[i] + d[lb] >= val;
        return res;
    }
    else
    {
        foo(i, L, r[lb] - 1)
            res += a[i] + d[lb] >= val;
        foo(i, l[rb], R - 1)
            res += a[i] + d[rb] >= val;
        lb += 1;
        rb -= 1;
        if(rb < lb)
            return res;
        foo(i, lb, rb)
            res += (srt + r[i]) - lower_bound(srt + l[i], srt + r[i], val - d[i]);
    }
    return res;
}

signed main()
{
    fastio;
    int q, i, L, R, val;
    char c;
    cin >> n >> q;
    rep(i, n) cin >> a[i], srt[i] = a[i];
    init();
    while(q--)
    {
        cin >> c >> L >> R >> val;
        if(c == 'M')
            update(L - 1, R, val);
        else
            cout << query(L - 1, R, val) << "\n";
    }
}