#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define quick ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int a[201][201];
int minabove[201];
int dep[201];

int main()
{
    int m,n,i,j,t,maxarea=0;
    cin >> m >> n;
    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            cin >> t;
            a[i][j]=t?a[i][j-1]+t:0;
        }
    }

    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(a[i][j]*a[i-1][j])
                minabove[j]=min(minabove[j],a[i][j]);
            else
                minabove[j]=a[i][j];

            dep[j]=minabove[j]?dep[j]+1:0;

            maxarea=max(maxarea,minabove[j]*dep[j]);
        }
    }

    cout << maxarea << "\n";
}
