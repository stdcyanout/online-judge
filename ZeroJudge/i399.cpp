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
    int a[3];
    cin >> a[0] >> a[1]>> a[2];
    sort(a,a+3,greater<int>());
    if(a[0]==a[2])
    {
        cout << "3 " << a[0] << "\n";
    }
    else if(a[0]==a[1]||a[1]==a[2])
    {
        cout << "2 " << a[0] << " " << a[2] << "\n";
    }
    else
    {
        cout << "1 " << a[0] << " " << a[1] << " " << a[2] << "\n";
    }
}