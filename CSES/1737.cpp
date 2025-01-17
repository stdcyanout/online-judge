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
    int val;
    node *L, *R;
    node(int v = 0) : val(v) {}
    void pull() { val = L -> val + R -> val; }
    node(node *L, node*R) : L(L), R(R) { pull(); }
};

int arr[200001];
vector<node*> seg;

node* build(int L, int R)
{
    if(L == R - 1)
        return new node(arr[L]);
    int M = (L + R) / 2;
    return new node(build(L, M), build(M, R));
}

node* update(node* tree, int L, int R, int pos, int val)
{
    tree = new node(*tree);
    if(L == R - 1)
    {
        tree -> val = val;
        return tree;
    }
    int M = (L + R) / 2;
    if(pos < M)
        tree -> L = update(tree -> L, L, M, pos, val);
    else
        tree -> R = update(tree -> R, M, R, pos, val);
    tree -> pull();
    return tree;
}

int query(node* tree, int L, int R, int l, int r)
{
    if(R <= l || r <= L)
        return 0;
    if(l <= L && R <= r)
        return tree -> val;
    int M = (L + R) / 2;
    return query(tree -> L, L, M, l, r) + query(tree -> R, M, R, l, r);
}

signed main()
{
    fastio;
    int n, q, i, t, k, a, b;
    cin >> n >> q;
    rep(i, n)
        cin >> arr[i];
    seg.pb(build(0, n));
    while(q--)
    {
        cin >> t;
        if(t == 1)
        {
            cin >> k >> a >> b;
            --k;
            seg[k] = update(seg[k], 0, n, a - 1, b);
        }
        else if(t == 2)
        {
            cin >> k >> a >> b;
            --k;
            cout << query(seg[k], 0, n, a - 1, b) << "\n";
        }
        else
        {
            cin >> k;
            --k;
            seg.pb(new node(*seg[k]));
        }
    }
}