#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define quick ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define vll vector<long long>
#define MOD 1000000007

using namespace std;

vll start={1,1,1,1,1,1,
           1,0,0,0,0,0,
           0,1,0,0,0,0,
           0,0,1,0,0,0,
           0,0,0,1,0,0,
           0,0,0,0,1,0};

inline ll location(ll a,ll b)
{
    return 6*a+b;
}

inline vll mutiply(vll a,vll b)
{
    vll c(36);
    ll i,j,k;
    for(i=0;i<6;i++)
    {
        for(j=0;j<6;j++)
        {
            for(k=0;k<6;k++)
            {
                c[location(i,j)]+=a[location(i,k)]*b[location(k,j)];
            }
            c[location(i,j)]%=MOD;
        }
    }
    return c;
}

vll fast_power(ll n)
{
    if(n==1)
        return start;
    vll res=fast_power(n>>1);
    if(n&1)
        return mutiply(mutiply(res,res),start);
    return mutiply(res,res);
}

int main()
{
    ll n,sum=0;
    cin >> n;
    if(n==0)
    {
        cout << 1 << "\n";
        return 0;
    }
    vll solve=fast_power(n);
    sum+=solve[location(5,0)]*16;
    sum+=solve[location(5,1)]*8;
    sum+=solve[location(5,2)]*4;
    sum+=solve[location(5,3)]*2;
    sum+=solve[location(5,4)];
    sum+=solve[location(5,5)];
    cout << sum%MOD << "\n";
}
