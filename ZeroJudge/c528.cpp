#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define int long long

using namespace std;

int dp[1000005];

signed main()
{
    fastIO
    int n,k,i,a;
    cin >> n >> k;
    deque<int> monoqueue;
    monoqueue.push_back(0);
    for(i=1;i<=n;i++)
    {
        cin >> a;
        if(monoqueue.front()<i-k)
            monoqueue.pop_front();
        dp[i]=a+dp[monoqueue.front()];
        while(!monoqueue.empty() && dp[monoqueue.back()]>dp[i])
            monoqueue.pop_back();
        monoqueue.push_back(i);
    }
    if(monoqueue.front()<n-k+1)
        monoqueue.pop_front();
    cout << dp[monoqueue.front()] << "\n";
}