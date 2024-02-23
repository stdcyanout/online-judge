#include <bits/stdc++.h>
#define int long long
using namespace std;

int dp[200001];

signed main()
{
    int n,q,a,b,i;
    cin >> n >> q;
    for(i=1;i<=n;i++)
    {
        cin >> dp[i];
        dp[i]^=dp[i-1];
    }
    while(q--)
    {
        cin >> a >> b;
        cout << (dp[b]^dp[a-1]) << "\n";
    }
}
