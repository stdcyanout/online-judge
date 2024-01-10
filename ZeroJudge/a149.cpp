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

int solve(int n)
{
    if(n/10)
        return (n%10)*solve(n/10);
    else
        return n;
}

signed main()
{
    fastIO
    int t,n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << solve(n) << "\n";
    }
}