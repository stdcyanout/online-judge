#include <bits/stdc++.h>

using namespace std;

bitset<1000001> b;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,i,j,times=0,Max=1,sum;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> j;
        if(b[j]==1)
            Max=max(Max,j);
        b[j]=1;
        times=max(times,j);
    }
    for(i=2;i<=times;i++)
    {
        sum=0;
        for(j=i;j<=times;j+=i)
            sum+=b[j];
        if(sum>=2)
            Max=max(Max,i);
    }
    cout << Max << "\n";
}
