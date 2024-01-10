#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define quick ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define eb emplace_back

using namespace std;

vector<int> graph[100005];
bitset<100005> vis;
int fardot,maxdep;

void dfs(int x,int dep)
{
    vis[x]=1;
    for(int i:graph[x])
    {
        if(!vis[i])
            dfs(i,dep+1);
    }
    if(dep>maxdep)
    {
        fardot=x;
        maxdep=dep;
    }
}

int main()
{
    quick

    int n,a,b,i;
    while(cin >> n)
    {
        for(i=0;i<n;i++)
            graph[i].clear();
        fardot=maxdep=0;

        for(i=0;i<n-1;i++)
        {
            cin >> a >> b;
            graph[a].eb(b);
            graph[b].eb(a);
        }

        vis<<=100005;
        dfs(0,0);
        vis<<=100005;
        dfs(fardot,0);
        cout << maxdep << "\n";
    }

}
