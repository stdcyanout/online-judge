#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m,i,j;
    cin >> n >> m;
    int a[n],b[m],sum=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin >> b[j];
        }
        a[i]=*max_element(b,b+m);
        sum+=a[i];
    }
    cout << sum << "\n";
    bool stricklycheck=0;
    for(i=0;i<n;i++)
    {
        if(sum%a[i]==0)
        {
            if(stricklycheck)
                cout << " ";
            cout << a[i];
            stricklycheck=1;
        }
    }
    if(!stricklycheck)
        cout << -1;
    cout << "\n";
}
