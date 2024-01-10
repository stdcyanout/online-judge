#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define quick ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

char graph[1001][1001];
bool vis[1001][1001];
int n,m,room;

void dfs(int i,int j)
{
    vis[i][j]=1;
    if(i-1>=0)
    {
        if(graph[i-1][j]=='.'&&(!vis[i-1][j]))
            dfs(i-1,j);
    }

    if(j-1>=0)
    {
        if(graph[i][j-1]=='.'&&(!vis[i][j-1]))
            dfs(i,j-1);
    }

    if(i+1<n)
    {
        if(graph[i+1][j]=='.'&&(!vis[i+1][j]))
            dfs(i+1,j);
    }

    if(j+1<m)
    {
        if(graph[i][j+1]=='.'&&(!vis[i][j+1]))
            dfs(i,j+1);
    }
}

int main()
{
    quick
    int i,j;
    cin >> n >> m;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            cin >> graph[i][j];

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        {
            if(graph[i][j]=='.'&&(!vis[i][j]))
            {
                dfs(i,j);
                room++;
            }
        }

    cout << room << "\n";
}
