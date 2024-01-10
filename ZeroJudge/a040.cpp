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

int digit(int n)
{
    if(n)
        return digit(n/10)+1;
    return 0;
}

int power(int a,int n)
{
    if(n)
        return a*power(a,n-1);
    return 1;
}

bool isarm(int n)
{
    int d=digit(n),arm=0;
    for(int i=0;i<d;i++)
    {
        arm+=power((n/power(10,i)%10),d);
    }
    if(arm==n)
        return 1;
    return 0;
}

signed main()
{
    fastIO
    int n,m;
    bool none=1;
    cin >> n >> m;
    while(n<=m)
    {
        if(isarm(n))
        {
            none=0;
            cout << n << " ";
        }
        ++n;
    }
    if(none)
        cout << "none";
    cout << "\n";
}