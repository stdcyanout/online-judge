#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define quick ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long

using namespace std;

ll check(ll k,ll digit)
{
    if(k<=0)
        return digit;
    else
        return check(k-9*(ll)(pow(10,digit))*(digit+1),digit+1);
}

ll start(ll digit)
{
    if(digit==1)
        return 1;
    else
        return start(digit-1)+9*(ll)(pow(10,digit-2))*(digit-1);
}

inline ll ans(ll k,ll s,ll d)
{
    return ((k-s)/(d*(ll)(pow(10,d-(k-s)%d-1)))+!((k-s)%d))%10;
}

int main()
{
    quick
    ll q,k,d,s;
    cin >> q;
    while(q--)
    {
        cin >> k;
        d=check(k,0);
        s=start(d);
        cout << ans(k,s,d) << "\n";
    }
}
