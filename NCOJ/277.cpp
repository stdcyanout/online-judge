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

int n[3], d[3], s[3];

signed main()
{
    fastio;
    int x1, y1, x2, y2, x3, y3, q, i;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    n[0] = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    n[1] = (x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3);
    n[2] = (x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1);
    sort(n, n + 3);
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    d[0] = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    d[1] = (x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3);
    d[2] = (x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1);
    sort(d, d + 3);
    cin >> q;
    while(q--)
    {
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        s[0] = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        s[1] = (x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3);
        s[2] = (x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1);
        sort(s, s + 3);
        if(s[0] == n[0] && s[1] == n[1] && s[2] == n[2])
            cout << "Nijika\n";
        else if(s[0] == d[0] && s[1] == d[1] && s[2] == d[2])
            cout << "Doritos\n";
        else
            cout << "None\n";
    }
}