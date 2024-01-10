#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

bitset<10000001> b;
int primesum[10000001];

int main()
{
    fastIO
    int i,j;
    b[1]=1;
    for(i=2;i<=3163;i++)
    {
        if(!b[i])
        {
            for(j=2;i*j<=10000000;j++)
            {
                b[i*j]=1;
            }
        }
    }

    for(i=2;i<=10000000;i++)
    {
        primesum[i]=primesum[i-1]+!b[i];
    }

    int m,n;
    cin >> m;
    while(m--)
    {
        cin >> n;
        cout << primesum[n] << "\n";
    }
}
