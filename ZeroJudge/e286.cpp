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
    int a[20],i;
    for(i=0;i<20;i++)
    {
        if((i+1)%5)
            cin >> a[i];
        else
            a[i]=a[i-1]+a[i-2]+a[i-3]+a[i-4];
    }
    cout << a[4] << ":" << a[9] << "\n" << a[14] << ":" << a[19] << "\n";
    if(a[4]>a[9] && a[14]>a[19])
        cout << "Win\n";
    else if(a[4]<a[9] && a[14]<a[19])
        cout << "Lose\n";
    else
        cout << "Tie\n" << "\n";
}