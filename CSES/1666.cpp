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

int anc[100005], sz[100005];

int find(int i)
{
    if(i == anc[i]) return i;
    return anc[i] = find(anc[i]);
}

void uni(int a, int b)
{
    a = find(a), b = find(b);
    if(a != b)
    {
        if(sz[a] < sz[b])
            swap(a, b);
        anc[b] = a;
        sz[a] += sz[b];
    }
}

signed main()
{
    fastio;
    int n, m, a, b, i;
    cin >> n >> m;
    iota(anc, anc + n + 1, 0);
    fill(sz, sz + n + 1, 1);
    while(m--)
    {
        cin >> a >> b;
        uni(a, b);
    }
    vector<int> boss;
    foo(i, 1, n)
        if(i == find(i)) boss.pb(i);
    cout << boss.size() - 1 << "\n";
    rep(i, boss.size() - 1)
        cout << boss[i] << " " << boss[i + 1] << "\n";
}