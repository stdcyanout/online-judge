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

int a[501][501];

signed main()
{
    fastIO
    int n,m,i,j,w,x,y,z;
    while(cin >> n >> m)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                cin >> a[i][j];
                a[i][j]=a[i][j]+a[i-1][j]+a[i][j-1]-a[i-1][j-1];
            }
        }

        while(m--)
        {
            cin >> w >> x >> y >> z;
            cout << a[y][z]-a[w-1][z]-a[y][x-1]+a[w-1][x-1] << "\n";
        }
    }
}