#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,i,j;
    while(cin >> n)
    {
        int a[n][n];
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin >> a[i][j];

        int sx[n]={};
        int sy[n]={};
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                sx[i]+=a[i][j];
                sy[j]+=a[i][j];
            }

        int sumx=0,sumy=0;
        for(i=0;i<n;i++)
        {
            sx[i]%=2;
            sumx+=sx[i];
        }
        for(i=0;i<n;i++)
        {
            sy[i]%=2;
            sumy+=sy[i];
        }

        if(sumx==0&&sumy==0)
            cout << "OK\n";
        else if(sumx==1&&sumy==1)
        {
            for(i=0;i<n;i++)
                if(sx[i]==1)
                    break;
            for(j=0;j<n;j++)
                if(sy[j]==1)
                    break;
            cout << "Change bit (" << i+1 << "," << j+1 << ")\n";
        }
        else
            cout << "Corrupt\n";
    }
}
