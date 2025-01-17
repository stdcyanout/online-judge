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
 
const int INF = 0x3F3F3F3F3F3F3F3F;
int a[200001], seg[800005], tag[800005];
 
bool cmp1(const array<int, 4>& a, const array<int, 4>& b)
{
    return a[1] > b[1];
}
 
bool cmp2(const array<int, 4>& a, const array<int, 4>& b)
{
    return a[0] < b[0];
}
 
void pull(int id)
{
    seg[id] = seg[lc] + seg[rc];
}
 
void push(int L, int R, int id)
{
    if(tag[id])
    {
        int M = (L + R) / 2;
        seg[lc] = (M - L) * tag[id];
        seg[rc] = (R - M) * tag[id];
        tag[lc] = tag[id];
        tag[rc] = tag[id];
        tag[id] = 0;
    }
}
 
void build(int L, int R, int id)
{
    if(L == R - 1)
    {
        seg[id] = a[L];
        return;
    }
    int M = (L + R) / 2;
    build(L, M, lc);
    build(M, R, rc);
    pull(id);
}
 
void update(int L, int R, int id, int l, int r, int val)
{
    if(R <= l || r <= L)
        return;
    if(l <= L && R <= r)
    {
        seg[id] = (R - L) * val;
        tag[id] = val;
        return;
    }
    int M = (L + R) / 2;
    push(L, R, id);
    update(L, M, lc, l, r, val);
    update(M, R, rc, l, r, val);
    pull(id);
}
 
int query(int L, int R, int id, int l, int r)
{
    if(R <= l || r <= L)
        return 0;
    if(l <= L && R <= r)
        return seg[id];
    int M = (L + R) / 2;
    push(L, R, id);
    return query(L, M, lc, l, r) + query(M, R, rc, l, r);
}
 
signed main()
{
    fastio;
    int prefix[200001];
    array<int, 4> t[200001];
    stack<int> s;
    int n, q, i, j;
    cin >> n >> q;
    rep(i, n)
    {
        cin >> a[i];
        prefix[i + 1] = prefix[i] + a[i];
    }
    rep(i, q)
    {
        t[i][0] = i;
        cin >> t[i][1] >> t[i][2];
        --t[i][1];
    }
    sort(t, t + q, cmp1);
    build(0, n, 0);
    j = 0;
    a[n] = INF;
    s.push(n);
    oof(i, n - 1, 0)
    {
        while(a[i] >= a[s.top()])
            s.pop();
        update(0, n, 0, i, s.top(), a[i]);
        while(t[j][1] == i)
        {
            t[j][3] = query(0, n, 0, t[j][1], t[j][2]) - (prefix[t[j][2]] - prefix[t[j][1]]);
            ++j;
        }
        s.push(i);
    }
    sort(t, t + q, cmp2);
    rep(i, q)
        cout << t[i][3] << "\n";
}