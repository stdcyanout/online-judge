#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int k,q,r,i,j;
    cin >> k >> q >> r;
    string s,sprime[q];
    int p;
    cin >> s;
    for(i=0;i<q;i++)
    {
        if(i>0)
            s=sprime[i-1];
        sprime[i]=s;
        for(j=0;j<k;j++)
        {
            cin >> p;
            sprime[i][p-1]=s[j];
        }
    }

    for(i=0;i<r;i++)
    {
        for(j=0;j<q;j++)
            cout << sprime[j][i];
        cout << "\n";
    }
}
