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

int a[1001];
set<int> s;
vector<int> masks, ill;

int bitcnt(int n)
{
    int cnt = 0;
    while(n)
    {
        ++cnt;
        n &= (n - 1);
    }
    return cnt;
}

signed main()
{
    fastio;
    int n, k, t, i, j, p, tmp;
    string str;
    cin >> n >> k >> t;
    rep(i, k) rep(j, k) rep(p, k)
        s.insert((1 << i) | (1 << j) | (1 << p));
    rep(i, 1 << k)
    {
        if(bitcnt(i) == t)
            masks.pb(i);
    }
    rep(i, n)
    {
        cin >> str;
        a[i] = stoi(str, nullptr, 2);
        s.erase(a[i]);
    }
    for(auto it = s.begin(); it != s.end(); ++it)
    {
        tmp = *it;
        for(int mask : masks)
        {
            rep(i, n)
            {
                if((a[i] & mask) == (tmp & mask))
                    break;
            }
            if(i == n)
            {
                ill.pb(tmp);
                break;
            }
        }
    }
    for(int t : ill)
        s.erase(t);
    if(s.empty())
        cout << "none\n";
    else
    {
        tmp = *s.begin();
        oof(i, k - 1, 0)
            cout << ((tmp >> i) & 1);
        cout << "\n";
    }
}