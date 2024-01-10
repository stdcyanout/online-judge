#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > turn(vector<vector<int> > v)
{
    int r=v.size();
    int c=v[0].size();
    vector<vector<int> > vprime(c,vector<int>(r));
    int i,j;
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            vprime[c-j-1][i]=v[i][j];

    return vprime;

}

vector<vector<int> > change(vector<vector<int> > v)
{
    int r=v.size();
    int c=v[0].size();
    vector<vector<int> > vprime(r,vector<int>(c));
    int i,j;
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            vprime[r-i-1][j]=v[i][j];

    return vprime;
}

int main()
{
    int i,j;
    int r,c,m;

    while(cin >> r >> c >> m)
    {
        vector<vector<int> > v(r,vector<int>(c));
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                cin >> v[i][j];

        vector<int> modify(m);
        for(i=0;i<m;i++)
            cin >> modify[i];

        for(i=m-1;i>=0;i--)
        {
            if(modify[i]==0)
                v=turn(v);
            else if(modify[i]==1)
                v=change(v);
        }

        r=v.size();
        c=v[0].size();

        cout << r << " " << c << "\n";

        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                cout << v[i][j];
                if(j!=c-1)
                    cout << " ";
            }
            cout << "\n";
        }

    }
}
