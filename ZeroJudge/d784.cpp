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
    int n,t,tmp,amax,cmax;
    cin >> n;
    while(n--)
    {
        cin >> t;
        amax=LONG_LONG_MIN;
        cmax=0;
        while(t--)
        {
            cin >> tmp;
            cmax+=tmp;
            amax=max(amax,cmax);
            if(cmax<0)
                cmax=0;
        }
        cout << amax << "\n";
    }
}