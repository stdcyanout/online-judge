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
    int n,m,i,j,cnt=0;
    while(cin >> n >> m && (n || m))
    {
        cnt++;
        int a[n],b[m];
        for(i=0;i<n;i++)
            cin >> a[i];
        for(i=0;i<m;i++)
            cin >> b[i];

        int lcs[n+1][m+1];
        for(i=0;i<n+1;i++)
            lcs[i][0]=0;
        for(i=0;i<m+1;i++)
            lcs[0][i]=0;

        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(a[i]==b[j])
                    lcs[i+1][j+1]=lcs[i][j]+1;
                else
                    lcs[i+1][j+1]=max(lcs[i+1][j],lcs[i][j+1]);
            }
        }

        cout << "Twin Towers #" << cnt << "\nNumber of Tiles : " << lcs[n][m] << "\n\n";
    }
}