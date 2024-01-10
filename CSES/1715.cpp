#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define quick ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define MOD 1000000007

using namespace std;

ll a[26],fact[1000001];

ll fast_power(ll a,ll n)
{
    if(n==0)
        return 1;
    ll res=fast_power(a,n>>1);
    if(n&1)
        return res*res%MOD*a%MOD;
    return res*res%MOD;
}

int main()
{
    ll i,ans;
    fact[0]=1;
    for(i=1;i<=1000000;i++)
        fact[i]=fact[i-1]*i%MOD;

    string s;
    cin >> s;
    stringstream ss;
    char c;
    ss << s;
    while(ss >> c)
    {
        a[(ll)(c-'a')]++;
    }

    ans=fact[s.length()];

    for(i=0;i<26;i++)
    {
        if(a[i])
            ans=ans*fast_power(fact[a[i]],MOD-2)%MOD;
    }

    cout << ans << "\n";
}
