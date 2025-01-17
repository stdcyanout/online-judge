#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fastio ios_base::sync_with_stdio(false),cin.tie(0);
#define safe cerr << "\e[1;31m" << __PRETTY_FUNCTION__ << " line " << __LINE__ << " safe\e[0m\n";
// #define int int64_t
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

int dat[4001][5], anc[4001], rk[4001];
tuple<int64_t, int, int> edge[8000000];

int find(int i)
{
    if(anc[i] == i) return i;
    return anc[i] = find(anc[i]);
}

int main()
{
    fastio;
    int d, n, i, j, k, a, b, group, last = -1, sz = 0;
    int64_t dis;
    cin >> d >> n;
    rep(i, n)
    {
        anc[i] = i;
        rep(j, d) cin >> dat[i][j];
        rep(j, i)
        {
            dis = 0;
            rep(k, d) dis += abs(dat[i][k] - dat[j][k]);
            edge[sz++] = {dis, i, j};
        }
    }
    sort(edge, edge + sz);
    group = n;
    rep(i, sz)
    {
        tie(dis, a, b) = edge[i];
        a = find(a), b = find(b);
        if(a != b)
        {
            if(dis == last)
                break;
            last = dis;
            group--;
            if(rk[a] > rk[b])
                swap(a, b);
            anc[b] = a;
            rk[a] += rk[b];
        }
    }
    cout << group + 1 << "\n";
}