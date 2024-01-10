#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define RED "\e[1;31m"
#define RESET "\e[0m"
#define int long long

using namespace std;

void debug()
{
    cerr << "\n" << RESET;
}
template<class T,class ...U> void debug(T a,U ...b)
{
    cerr << RED << a << " ", debug(b...);
}

signed main()
{
    fastIO
    int n,d,x,y,e=0;
    bool h=1;
    cin >> n >> d >> x;
    while(--n)
    {
        cin >> y;
        if(h&&y>=x+d)
        {
            e+=y-x;
            x=y;
            h=0;
        }
        if(!h&&y<=x-d)
        {
            x=y;
            h=1;
        }
    }
    cout << e << "\n";
}