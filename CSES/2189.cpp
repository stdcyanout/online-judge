#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define quick ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define pll pair<long long,long long>
#define x first
#define y second

using namespace std;

int main()
{
    quick
    ll t;
    pll a,b,c;
    ll n;
    cin >> t;
    while(t--)
    {
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
        n=(b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
        if(n>0)
            cout << "LEFT" << "\n";
        else if(n<0)
            cout << "RIGHT" << "\n";
        else
            cout << "TOUCH" << "\n";
    }
}
