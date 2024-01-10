#include <bits/stdc++.h>

using namespace std;

int n,m;
int a[50][50];

int sum(int x,int y,int d)
{
    int s=0,i,j;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            if(abs(x-i)+abs(y-j)<=d)
                s+=a[i][j];
    s-=a[x][y];
    return s%10;
}

int main()
{
    int i,j,num=0;
    vector<pair<int,int>> ans;
    cin >> n >> m;
    for(i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> a[i][j];

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            if(sum(i,j,a[i][j])==0)
            {
                num+=1;
                ans.push_back(make_pair(i,j));
            }

    cout << num << endl;
    for(i=0;i<ans.size();i++)
    {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
}
