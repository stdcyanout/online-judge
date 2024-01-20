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

bool isprime(int n)
{
    for(int i=2;i*i<=n;i++)
    {
        if(!(n%i))
            return 0;
    }
    return 1;
}

signed main()
{
    fastIO
    int a,b,i;
    while(cin >> a >> b)
    {
        int cnt=0;
        for(i=max(2ll,a);i<=b;i++)
        {

            if(i<=5||i%6==1||i%6==5)
            {
                cnt+=isprime(i);
            }
        }
        cout << cnt << "\n";
    }
}