#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define quick ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

string s;
bool vis[9][9];
int ans=0;

void solve(int x,int y,int n)
{
    if(x<1||y<1||x>7||y>7||vis[x][y])
        return;
    if(x==1&&y==7&&n<48)
        return;
    if(n==48)
    {
        ans++;
        return;
    }
    if(vis[x-1][y]&&vis[x+1][y]&&!vis[x][y-1]&&!vis[x][y+1])
        return;
    if(!vis[x-1][y]&&!vis[x+1][y]&&vis[x][y-1]&&vis[x][y+1])
        return;
    vis[x][y]=1;
    if(s[n]=='R')
        solve(x+1,y,n+1);
    if(s[n]=='L')
        solve(x-1,y,n+1);
    if(s[n]=='U')
        solve(x,y-1,n+1);
    if(s[n]=='D')
        solve(x,y+1,n+1);
    if(s[n]=='?')
    {
        solve(x+1,y,n+1);
        solve(x-1,y,n+1);
        solve(x,y-1,n+1);
        solve(x,y+1,n+1);
    }
    vis[x][y]=0;
}

int main()
{
    quick
    for(int i=1;i<=7;i++)
    {
        vis[0][i]=1;
        vis[8][i]=1;
        vis[i][0]=1;
        vis[i][8]=1;
    }
    cin >> s;
    solve(1,1,0);
    cout << ans << "\n";
}
