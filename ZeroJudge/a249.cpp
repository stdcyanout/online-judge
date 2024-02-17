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
    int n,d,i,j,ans;
    cin >> n;
    while(n--)
    {
        cin >> d >> i;
        ans=1;
        --i;
        for(j=0;j<d-1;j++)
        {
            if(i&(1<<j))
                ans=(ans<<1)+1;
            else
                ans<<=1;
        }
        cout << ans << "\n";
    }
}