#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define quick ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long

using namespace std;

ll L(ll r,ll c)
{
    if(c==1||r==c)
        return r;
    else
    {
        ll a=L(r-1,c-1);
        ll b=L(r,c-1);
        return (a*b)/(b-a);
    }
}

int main()
{
    quick
    ll a,b;
    cin >> a >> b;
    cout << L(a,b) << "\n";
}
