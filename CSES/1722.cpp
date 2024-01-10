#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define quick ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define MOD 1000000007

using namespace std;

vector<ll> mutiply(vector<ll> a,vector<ll> b)
{
    vector<ll> c(4);
    c[0]=(a[0]*b[0]%MOD+a[1]*b[2]%MOD)%MOD;
    c[1]=(a[0]*b[1]%MOD+a[1]*b[3]%MOD)%MOD;
    c[2]=(a[2]*b[0]%MOD+a[3]*b[2]%MOD)%MOD;
    c[3]=(a[2]*b[1]%MOD+a[3]*b[3]%MOD)%MOD;
    return c;
}

vector<ll> fastpow(vector<ll> a,ll n)
{
    if(n==1)
        return a;
    vector<ll> res=fastpow(a,n>>1);
    if(n&1)
        return mutiply(mutiply(res,res),a);
    return mutiply(res,res);
}

int main()
{
    quick

    ll n;
    cin >> n;
    vector<ll> a={1,1,1,0};
    if(n>1)
        cout << fastpow(a,n-1)[0] << "\n";
    else
        cout << n << "\n";
}
