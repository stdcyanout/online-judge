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
using namespace std;

void debug()
{
    cerr << "\n" << RESET;
}
template<class T,class ...U> void debug(T a,U ...b)
{
    cerr << RED << a << " ", debug(b...);
}

signed main()
{
    fastIO
    int t,n,c,d,i,j;
    cin >> t;
    while(t--)
    {
        cin >> n >> c >> d;
        vector<int> a(n*n),b;
        rep(i,n*n) cin >> a[i];
        rep(i,n) rep(j,n) b.pb(c*i+d*j);
        sort(all(a));
        sort(all(b));
        rep(i,n*n)
        {
            if(a[i]-b[i]!=a[0]-b[0])
            {
                cout << "NO\n";
                break;
            }
            if(i==n*n-1) cout << "YES\n";
        }
    }
}