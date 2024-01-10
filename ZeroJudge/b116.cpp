#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int m,n,i,j,t;
    while(cin >> m >> n)
    {
        for(i=0;i<m;i++)
        {
            bitset<100000> bs,tmp;
            bs[50000]=1;
            for(j=0;j<n;j++)
            {
                cin >> t;
                tmp=bs<<t;
                bs=bs>>t;
                bs|=tmp;
            }
            if(bs[50000])
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
}
