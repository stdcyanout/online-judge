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
    int t,n,i;
    cin >> t;
    for(i=1;i<=t;i++)
    {
        cout << "Case " << i << ": ";
        cin >> n;
        if((n%400==0)||(n%100!=0&&n%4==0))
            cout << "a leap year\n";
        else
            cout << "a normal year\n";
    }
}