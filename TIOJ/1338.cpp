#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include "lib1338.h"
#include <bits/stdc++.h>
using namespace std;

long long s[21][1000001];
long long g[21][1000001];

void init(int N, long long C[])
{
    int i,j,k=__lg(N),t;
    for(i=0;i<N;i++)
    {
        s[0][i]=g[0][i]=C[i];
    }
    for(i=1;i<=k;i++)
    {
        t=N-(1<<i)+1;
        for(j=0;j<t;j++)
        {
            s[i][j]=min(s[i-1][j],s[i-1][j+(1<<(i-1))]);
            g[i][j]=__gcd(g[i-1][j],g[i-1][j+(1<<(i-1))]);
        }
    }
}

int query(int L,int R)
{
    int k=__lg(R-L);
    return __gcd(g[k][L],g[k][R-(1<<k)])==min(s[k][L],s[k][R-(1<<k)]);
}