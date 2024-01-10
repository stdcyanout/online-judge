#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define quick ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int sum[1001][1001];

int main()
{
    quick
    int n,q,i,j,y1,x1,y2,x2;
    char c;
    cin >> n >> q;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cin >> c;
            if(c=='*')
                sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+1;
            else
                sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
        }
    }

    while(q--)
    {
        cin >> y1 >> x1 >> y2 >> x2;
        cout << sum[y2][x2]-sum[y2][x1-1]-sum[y1-1][x2]+sum[y1-1][x1-1] << "\n";
    }
}
