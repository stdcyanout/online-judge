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

int f(int x)
{
    if(x==1)
        return 1;
    else if(x&1)
        return f(x-1)+f(x+1);
    else
        return f(x/2);
}

signed main()
{
    fastIO
    int x;
    cin >> x;
    cout << f(x) << "\n";
}