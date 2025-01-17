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

int arr[200001], seg[800005], addtag[800005], settag[800005];

signed main()
{
    fastio;
    
    function<void(int)> pull = [&](int id) -> void 
    {
        seg[id] = seg[lc] + seg[rc];
    };

    function<void(int, int, int)> push = [&](int L, int R, int id) -> void 
    {
        int M = (L + R) / 2;
        if(settag[id])
        {
            seg[lc] = (M - L) * settag[id];
            seg[rc] = (R - M) * settag[id];
            settag[lc] = settag[id];
            settag[rc] = settag[lc];
            addtag[lc] = 0;
            addtag[rc] = 0;
            settag[id] = 0;
        }
        else if(addtag[id])
        {
            seg[lc] += (M - L) * addtag[id];
            seg[rc] += (R - M) * addtag[id];
            if(settag[lc])
                settag[lc] += addtag[id];
            else
                addtag[lc] += addtag[id];
            if(settag[rc])
                settag[rc] += addtag[id];
            else
                addtag[rc] += addtag[id];
            addtag[id] = 0;
        }
    };

    function<void(int, int, int)> build = [&](int L, int R, int id) -> void 
    {
        if(L == R - 1)
        {
            seg[id] = arr[L];
            return;
        }
        int M = (L + R) / 2;
        build(L, M, lc);
        build(M, R, rc);
        pull(id);
    };

    function<void(int, int, int, int, int, int)> add = [&](int L, int R, int id, int l, int r, int val) -> void
    {
        if(R <= l || r <= L)
            return;
        if(l <= L && R <= r)
        {
            seg[id] += (R - L) * val;
            if(settag[id])
                settag[id] += val;
            else
                addtag[id] += val;
            return;
        }
        int M = (L + R) / 2;
        push(L, R, id);
        add(L, M, lc, l, r, val);
        add(M, R, rc, l, r, val);
        pull(id);
    };

    function<void(int, int, int, int, int, int)> set = [&](int L, int R, int id, int l, int r, int val) -> void
    {
        if(R <= l || r <= L)
            return;
        if(l <= L && R <= r)
        {
            seg[id] = (R - L) * val;
            settag[id] = val;
            addtag[id] = 0;
            return;
        }
        int M = (L + R) / 2;
        push(L, R, id);
        set(L, M, lc, l, r, val);
        set(M, R, rc, l, r, val);
        pull(id);
    };

    function<int(int, int, int, int, int)> query = [&](int L, int R, int id, int l, int r) -> int
    {
        if(R <= l || r <= L)
            return 0;
        if(l <= L && R <= r)
            return seg[id];
        int M = (L + R) / 2;
        push(L, R, id);
        return query(L, M, lc, l, r) + query(M, R, rc, l, r);
    };

    int n, q, t, a, b, x, i;
    cin >> n >> q;
    rep(i, n)
        cin >> arr[i];
    build(0, n, 0);
    while(q--)
    {
        cin >> t;
        if(t == 1)
        {
            cin >> a >> b >> x;
            add(0, n, 0, a - 1, b, x);
        }
        else if(t == 2)
        {
            cin >> a >> b >> x;
            set(0, n, 0, a - 1, b, x);
        }
        else
        {
            cin >> a >> b;
            cout << query(0, n, 0, a - 1, b) << "\n";
        }
    }
}