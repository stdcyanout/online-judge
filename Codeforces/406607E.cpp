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

const int sz = 200000001;
vector<int> v;
int a[200001];

struct node
{
    int val;
    node *L, *R;
    node() : val(0) { L = R = nullptr; }
    void pull() { val = 0; if(L) val += L -> val; if(R) val += R -> val; }
};

void update(node* &tr, int L, int R, int pos, int val)
{
    if(!tr) tr = new node();
    if(L == R - 1)
    {
        tr -> val += val;
        return;
    }
    int M = (L + R) / 2;
    if(pos < M)
        update(tr -> L, L, M, pos, val);
    else
        update(tr -> R, M, R, pos, val);
    tr -> pull();
}

int min(node* tr, int L, int R)
{
    if(L == R - 1)
        return L;
    int M = (L + R) / 2;
    if(tr -> L && tr -> L -> val)
        return min(tr -> L, L, M);
    else
        return min(tr -> R, M, R);
}

int max(node* tr, int L, int R)
{
    if(L == R - 1)
        return L;
    int M = (L + R) / 2;
    if(tr -> R && tr -> R -> val)
        return max(tr -> R, M, R);
    else
        return max(tr -> L, L, M);
}

int mex(node* tr, int L, int R)
{
    if(!tr || L == R - 1)
        return L;
    int M = (L + R) / 2;
    if(tr -> L && tr -> L -> val == M - L)
        return mex(tr -> R, M, R);
    else
        return mex(tr -> L, L, M);
}

signed main()
{
    fastio;
    int n, q, t, i;
    cin >> n >> q;
    node *tr = nullptr;
    rep(i, n) cin >> t, update(tr, 0, sz, t, 1);
    string s;
    cin >> s;
    int buf = 0;
    rep(i, q)
    {
        if(s[i] == '1')
        {
            t = min(tr, 0, sz);
            buf += t;
            update(tr, 0, sz, t, -1);
        }
        if(s[i] == '2')
        {
            t = max(tr, 0, sz);
            buf += t;
            update(tr, 0, sz, t, -1);
        }
        if(s[i] == '3')
        {
            t = mex(tr, 0, sz);
            buf += t;
            update(tr, 0, sz, t, 1);
        }
        if(i % 10 == 9 && i != q - 1)
            cout << buf << " ", buf = 0;
    }
    cout << buf << "\n";
}