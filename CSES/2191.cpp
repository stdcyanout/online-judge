#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define quick ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define pll pair<long long,long long>
#define x first
#define y second

using namespace std;

inline ll cross(pll a,pll b,pll c)
{
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}

int main()
{
    quick
    ll n,area=0;
    pll a,last,current;
    cin >> n;
    cin >> a.x >> a.y >> last.x >> last.y;
    n-=2;
    while(n--)
    {
        cin >> current.x >> current.y;
        area+=cross(a,last,current);
        last=current;
    }
    cout << abs(area) << "\n";
}
