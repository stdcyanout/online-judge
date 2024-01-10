#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define quick ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

vector<vector<char>> graph;
vector<vector<bool>> vis;
int n,m;

int dfs(int x,int y)
{
    vis[x][y]=1;

    bool up=0,right=0,down=0,left=0;
    if(graph[x][y]=='F')
        right=down=1;
    if(graph[x][y]=='H')
        right=left=1;
    if(graph[x][y]=='7')
        left=down=1;
    if(graph[x][y]=='I')
        up=down=1;
    if(graph[x][y]=='X')
        up=down=left=right=1;
    if(graph[x][y]=='L')
        right=up=1;
    if(graph[x][y]=='J')
        left=up=1;

    int all=0;

    if(up)
    {
        if(x-1<0)
            up=0;
        else if((graph[x-1][y]=='X'||graph[x-1][y]=='I'||graph[x-1][y]=='7'||graph[x-1][y]=='F')&&(!vis[x-1][y]))
            all+=dfs(x-1,y);
        else
            up=0;
    }

    if(right)
    {
        if(y+1>=m)
            right=0;
        else if((graph[x][y+1]=='X'||graph[x][y+1]=='H'||graph[x][y+1]=='7'||graph[x][y+1]=='J')&&(!vis[x][y+1]))
            all+=dfs(x,y+1);
        else
            right=0;
    }

    if(down)
    {
        if(x+1>=n)
            down=0;
        else if((graph[x+1][y]=='X'||graph[x+1][y]=='I'||graph[x+1][y]=='L'||graph[x+1][y]=='J')&&(!vis[x+1][y]))
            all+=dfs(x+1,y);
        else
            down=0;
    }

    if(left)
    {
        if(y-1<0)
            left=0;
        else if((graph[x][y-1]=='X'||graph[x][y-1]=='H'||graph[x][y-1]=='L'||graph[x][y-1]=='F')&&(!vis[x][y-1]))
            all+=dfs(x,y-1);
        else
            left=0;
    }

    if(!(up||right||down||left))
        return 1;
    else
        return all+1;
}

int main()
{
    quick

    int i,j;
    cin >> n >> m;
    graph.resize(n,vector<char>(m));
    vis.resize(n,vector<bool>(m));
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            cin >> graph[i][j];

    int maxdep=0;

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        {
            if(!vis[i][j]&&graph[i][j]!='0')
                maxdep=max(maxdep,dfs(i,j));
        }

    cout << maxdep << "\n";
}
