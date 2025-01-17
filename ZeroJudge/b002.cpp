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
#define inf 0x3f3f3f3f3f3f3f3f
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

bool a[10][10];
int mint;

void press(int n)
{
    if((n/10)-1>=0) a[(n/10)-1][(n%10)]=!a[(n/10)-1][(n%10)];
    if((n%10)-1>=0) a[(n/10)][(n%10)-1]=!a[(n/10)][(n%10)-1];
    a[(n/10)][(n%10)]=!a[(n/10)][(n%10)];
    if((n%10)+1<10) a[(n/10)][(n%10)+1]=!a[(n/10)][(n%10)+1];
    if((n/10)+1<10) a[(n/10)+1][(n%10)]=!a[(n/10)+1][(n%10)];
}

bool check(int n)
{
    if(n<10) return true;
    if(n<=90) return !a[(n/10)-1][(n%10)];
    if(n<99) return !a[(n/10)-1][(n%10)] && !a[(n/10)][(n%10)-1];
    return !a[(n/10)-1][(n%10)] && !a[(n/10)][(n%10)-1] && !a[(n/10)][(n%10)];
}

void dfs(int n,int t)
{
    if(n==100)
    {
        mint=min(mint,t);
        return;
    }
    if(check(n)) dfs(n+1,t);
    press(n);
    if(check(n)) dfs(n+1,t+1);
    press(n);
}

signed main()
{
    fastio;
    char c;
    int n,i,j;
    cin >> n;
    while(n--)
    {
        mint=inf;
        rep(i,10) rep(j,10)
        {
            cin >> c;
            if(c=='O')
                a[i][j]=1;
            else
                a[i][j]=0;
        }
        dfs(0,0);
        cout << mint << "\n";
    }
}