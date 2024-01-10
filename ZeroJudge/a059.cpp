#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define RED "\e[1;31m"
#define RESET "\e[0m"
#define int long long
#define eps 1e-6

using namespace std;

void debug()
{
    cerr << RESET;
}
template<class T,class ...U> void debug(T a,U ...b)
{
    cerr << RED << a << " ", debug(b...);
}

signed main()
{
    fastIO
    int n,i,a,b,sum;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        sum=0;
        cin >> a >> b;
        a=ceil(sqrt(a)-eps);
        b=floor(sqrt(b)+eps);
        while(a<=b)
        {
            sum+=a*a;
            ++a;
        }
        cout << "Case " << i << ": " << sum << "\n";
    }
}