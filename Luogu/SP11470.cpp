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

struct node
{
    int val, tag;
    node *L, *R;
    node(int v = 0) : val(v) {}
    void pull() { val = L -> val + R -> val; }
    node(node *L, node*R) : L(L), R(R) { pull(); }
};

int arr[100005];
node* seg[100005];

node* build(int L, int R)
{
    if(L == R - 1)
        return new node(arr[L]);
    int M = (L + R) / 2;
    return new node(build(L, M), build(M, R));
}

node* update(node* tree, int L, int R, int l, int r, int d)
{
    if(R <= l || r <= L)
        return tree;
    tree = new node(*tree);
    if(l <= L && R <= r)
    {
        tree -> tag += d;
        return tree;
    }
    int M = (L + R) / 2;
    tree -> L = update(tree -> L, L, M, l, r, d);
    tree -> R = update(tree -> R, M, R, l, r, d);
    tree -> val = tree -> L -> val + tree -> R -> val + (M - L) * tree -> L -> tag + (R - M) * tree -> R -> tag;
    return tree;
}

int query(node* tree, int L, int R, int l, int r)
{
    if(R <= l || r <= L)
        return 0;
    if(l <= L && R <= r)
        return tree -> val + (R - L) * tree -> tag;
    int M = (L + R) / 2;
    return query(tree -> L, L, M, l, r) + query(tree -> R, M, R, l, r) + (min(R, r) - max(L, l)) * tree -> tag;
}

signed main()
{
    fastio;
    int n, m, i, t = 0, l, r, d;
    char op;
    cin >> n >> m;
    rep(i, n)
        cin >> arr[i];
    seg[0] = build(0, n);
    while(m--)
    {
        cin >> op;
        if(op == 'C')
        {
            cin >> l >> r >> d;
            seg[t + 1] = update(seg[t], 0, n, l - 1, r, d);
            t++;
        }
        if(op == 'Q')
        {
            cin >> l >> r;
            cout << query(seg[t], 0, n, l - 1, r) << "\n";
        }
        if(op == 'H')
        {
            cin >> l >> r >> d;
            cout << query(seg[d], 0, n, l - 1, r) << "\n";
        }
        if(op == 'B')
            cin >> t;
    }
}