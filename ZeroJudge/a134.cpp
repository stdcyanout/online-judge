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
    int i;
    vector<int> dp(40);
    dp[0]=0;
    dp[1]=1;
    for(i=2;i<40;i++)
        dp[i]=dp[i-1]+dp[i-2];

    int n,t;
    cin >> n;
    while(n--)
    {
        cin >> t;
        cout << t << " = ";
        for(auto it=upper_bound(dp.begin(),dp.end(),t)-1;it!=dp.begin()+1;--it)
        {
            if(t-*it>=0)
            {
                cout << 1;
                t-=*it;
            }
            else
                cout << 0;
        }
        cout << " (fib)\n";
    }
}