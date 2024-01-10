#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define quick ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
using namespace std;

int main()
{
    quick
    ll t,y,x,y0,x0;
    cin >> t;
    while(t--)
    {
        cin >> y >> x;
        y0=(y>>1<<1)*(y>>1<<1)+(y&1);
        x0=(((x-1)>>1<<1)+1)*(((x-1)>>1<<1)+1)+((x-1)&1);
        if(y>=x)
        {
            if(y&1)
                y0+=x-1;
            else
                y0-=x-1;
            cout << y0 << "\n";
        }
        else
        {
            if(x&1)
                x0-=y-1;
            else
                x0+=y-1;
            cout << x0 << "\n";
        }
    }
}
