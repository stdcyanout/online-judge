#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define RED "\e[1;31m"
#define RESET "\e[0m"
#define int long long

using namespace std;

void debug()
{
    cerr << "\n" << RESET;
}
template<class T,class ...U> void debug(T a,U ...b)
{
    cerr << RED << a << " ", debug(b...);
}

int calc(int a,int b,int c,int x)
{
    return a*x*x+b*x+c;
}

signed main()
{
    fastIO
    int a1,b1,c1,a2,b2,c2,n,i,maxearn=LONG_LONG_MIN;
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2 >> n;
    for(i=0;i<=n;i++)
        maxearn=max(maxearn,calc(a1,b1,c1,i)+calc(a2,b2,c2,n-i));
    cout << maxearn << "\n";
}