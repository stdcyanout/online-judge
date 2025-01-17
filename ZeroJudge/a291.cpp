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

int correct[4], password[4];

void solve()
{
    int solved[4] = {}, fnd[4] = {}, i, j, a = 0, b = 0;
    rep(i, 4)
    {
        if(correct[i] == password[i])
            a++, solved[i] = fnd[i] = 1;
    }
    rep(i, 4)
    {
        if(solved[i]) continue;
        rep(j, 4)
        {
            if(i != j)
            {
                if(fnd[j]) continue;
                if(correct[i] == password[j])
                    b++, solved[i] = fnd[j] = 1;
            }
        }
    }
    cout << a << "A" << b << "B\n";
}

signed main()
{
    fastio;
    while(cin >> correct[0] >> correct[1] >> correct[2] >> correct[3])
    {
        int n;
        cin >> n;
        while(n--)
        {
            cin >> password[0] >> password[1] >> password[2] >> password[3];
            solve();
        }
    }
}