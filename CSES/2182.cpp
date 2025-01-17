#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define RED "\e[1;31m"
#define RESET "\e[0m"
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
#define MOD 1000000007
using namespace std;

template<class T> void debug(T a)
{
    cout << a << "\n";
}
template<class T,class ...U> void debug(T a,U ...b)
{
    cout << a << " ", debug(b...);
}

int fp(int a,int n)
{
    if(n==0)
        return 1;
    int res=fp(a,n/2);
    res=res*res%MOD;
    if(n&1)
        return res*a%MOD;
    else
        return res;
}

signed main()
{
    fastIO
    int n,i;
    cin >> n;
    pii a[n];
    rep(i,n) cin >> a[i].F >> a[i].S;
    int x=1,y=1,tmpa=1,tmpb=1,z;
    rep(i,n)
    {
        x=x*(a[i].S+1)%MOD;
        y=y*((fp(a[i].F,a[i].S+1)-1)/(a[i].F-1))%MOD;
        tmpa=tmpa*fp(a[i].F,a[i].S);
        tmpb=tmpb*fp(a[i].F,a[i].S/2);
    }
    z=fp(tmpa,x/2);
    if(x&1) z*=tmpb;
    debug(x,y,z);
}