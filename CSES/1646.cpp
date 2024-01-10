#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define quick ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long

using namespace std;

ll sum[200000];

int main()
{
    quick
    ll n,q,t,i,a,b;
    cin >> n >> q;
    for(i=1;i<=n;i++)
    {
        cin >> t;
        sum[i]=sum[i-1]+t;
    }
    while(q--)
    {
        cin >> a >> b;
        cout << sum[b]-sum[a-1] << "\n";
    }
}
