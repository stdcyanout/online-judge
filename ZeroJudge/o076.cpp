#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int h[105];
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,i,tmp=1,ans=0;
    cin >> n;
    for(i=0;i<n;i++)
        cin >> h[i];
    for(i=0;i<n-1;i++)
    {
        if(h[i]>h[i+1])
        {
            tmp++;
        }
        else
        {
            ans=max(ans,tmp);
            tmp=1;
        }
    }
    ans=max(ans,tmp);
    cout << ans << "\n";
}