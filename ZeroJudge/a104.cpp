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

int a[1000];

signed main()
{
    fastIO
    int n,i;
    while(cin >> n)
    {
        for(i=0;i<n;i++)
            cin >> a[i];
        sort(a,a+n);
        for(i=0;i<n;i++)
            cout << a[i] << " \n"[i==n-1];
    }
}