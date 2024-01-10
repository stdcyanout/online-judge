#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int i,j;
    int n;
    cin >> n;
    vector<bool> v;
    int l,r;
    for(i=0;i<n;i++)
    {
        cin >> l >> r;
        if(v.size()<r)
            v.resize(r,0);
        for(j=0;j<r-l;j++)
            v[l+j]=1;
    }

    int sum=0;
    for(auto it=v.begin();it!=v.end();it++)
        sum+=*it;
    cout << sum << "\n";
}
