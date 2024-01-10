#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,i;
    cin >> n;
    vector<pair<int,int>> a(n+1);
    vector<int> b(n);

    a[i].first=a[i].second=0;
    for(i=1;i<=n;i++)
        cin >> a[i].first >> a[i].second;

    for(i=0;i<n;i++)
    {
        if(a[i+1].first==a[i].first&&a[i+1].second>a[i].second)
            b[i]=1;
        if(a[i+1].first>a[i].first&&a[i+1].second==a[i].second)
            b[i]=2;
        if(a[i+1].first==a[i].first&&a[i+1].second<a[i].second)
            b[i]=3;
        if(a[i+1].first<a[i].first&&a[i+1].second==a[i].second)
            b[i]=4;
    }

    int ans[3]={};

    for(i=0;i<n-1;i++)
    {
        if(b[i]==1&&b[i+1]==4)
            ans[0]+=1;
        if(b[i]==4&&b[i+1]==3)
            ans[0]+=1;
        if(b[i]==3&&b[i+1]==2)
            ans[0]+=1;
        if(b[i]==2&&b[i+1]==1)
            ans[0]+=1;

        if(b[i]==1&&b[i+1]==2)
            ans[1]+=1;
        if(b[i]==2&&b[i+1]==3)
            ans[1]+=1;
        if(b[i]==3&&b[i+1]==4)
            ans[1]+=1;
        if(b[i]==4&&b[i+1]==1)
            ans[1]+=1;

        if(b[i]==1&&b[i+1]==3)
            ans[2]+=1;
        if(b[i]==3&&b[i+1]==1)
            ans[2]+=1;
        if(b[i]==2&&b[i+1]==4)
            ans[2]+=1;
        if(b[i]==4&&b[i+1]==2)
            ans[2]+=1;
    }

    cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
}
