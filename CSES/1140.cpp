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
 
int seg[2000005];
array<int, 3> p[200001];
vector<int> v;
 
bool cmp(const array<int, 3>& a, const array<int, 3>& b)
{
    return a[1] < b[1];
}
 
void pull(int id)
{
    seg[id] = max(seg[lc], seg[rc]);
}
 
void update(int L, int R, int id, int pos, int val)
{
    if(L == R - 1)
    {
        seg[id] = max(val, seg[id]);
        return;
    }
    int M = (L + R) / 2;
    if(pos < M)
        update(L, M, lc, pos, val);
    else
        update(M, R, rc, pos, val);
    pull(id);
}
 
int query(int L, int R, int id, int l, int r)
{
    if(R <= l || r <= L)
        return 0;
    if(l <= L && R <= r)
        return seg[id];
    int M = (L + R) / 2;
    return max(query(L, M, lc, l, r), query(M, R, rc, l, r));
}
 
signed main()
{
    fastio;
    int n, i, ans = 0, tmp;
    cin >> n;
    rep(i, n)
    {
        cin >> p[i][0] >> p[i][1] >> p[i][2];
        v.pb(p[i][0]);
        v.pb(p[i][1]);
    }
    sort(all(v));
    v.erase(unique(all(v)), v.end());
    rep(i, n)
    {
        p[i][0] = lower_bound(all(v), p[i][0]) - v.begin();
        p[i][1] = lower_bound(all(v), p[i][1]) - v.begin();
    }
    sort(p, p + n, cmp);
    rep(i, n)
    {
        tmp = query(0, v.size(), 0, 0, p[i][0]) + p[i][2];
        update(0, v.size(), 0, p[i][1], tmp);
        ans = max(ans, tmp);
    }
    cout << ans << "\n";
}