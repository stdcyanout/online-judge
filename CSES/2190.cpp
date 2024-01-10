#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define quick ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define pll pair<long long,long long>
#define x first
#define y second

using namespace std;

inline int crosssign(pll a,pll b,pll c)
{
    ll cross=(b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
    if(!cross)
        return 0;
    return (cross>0)?1:-1;
}

inline bool touch(pll a,pll b,pll c)
{
    ll dot=(b.x-a.x)*(c.x-a.x)+(b.y-a.y)*(c.y-a.y);
    return (dot<=0)&&(!crosssign(a,b,c));
}

int main()
{
    quick
    ll t;
    pll a,b,c,d;
    cin >> t;
    while(t--)
    {
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
        if(crosssign(a,b,c)*crosssign(a,b,d)<0 && crosssign(c,a,d)*crosssign(c,b,d)<0)
            cout << "YES" << "\n";
        else if(touch(a,c,d)||touch(b,c,d)||touch(c,a,b)||touch(d,a,b))
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
}
