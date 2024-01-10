#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m,a,b,i;
    vector<int> v;
    while(cin >> n >> m)
    {
        v.resize(n+1);
        v[0]=0;
        for(i=1;i<=n;i++)
        {
            cin >> v[i];
            v[i]+=v[i-1];
        }
        for(i=0;i<m;i++)
        {
            cin >> a >> b;
            cout << v[b]-v[a-1] << "\n";
        }
    }
}
