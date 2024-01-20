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

signed main()
{
    fastIO
    int n,g,i,j;
    while(cin >> n && n)
    {
        g=0;
        for(i=1;i<n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                g+=__gcd(i,j);
            }
        }
        cout << g << "\n";
    }
}