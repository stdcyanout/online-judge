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
    int t,a,b,i;
    cin >> t;
    for(i=1;i<=t;i++)
    {
        cin >> a >> b;
        if(!(a&1))
            ++a;
        if(!(b&1))
            --b;
        cout << "Case "<< i << ": " << ((b-a)/2+1)*((a+b)/2) << "\n";
    }
}