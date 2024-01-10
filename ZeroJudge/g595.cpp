#include <bits/stdc++.h>

using namespace std;

int main()
{
    int sum=0,n,i;
    cin >> n;
    int a[n];
    for(i=0;i<n;i++)
        cin >> a[i];
    for(i=0;i<n;i++)
    {
        if(a[i]==0)
        {
            if(i==0)
                sum+=a[1];
            else if(i==n-1)
                sum+=a[n-2];
            else
                sum+=min(a[i-1],a[i+1]);
        }
    }
    cout << sum << endl;
}
