#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define quick ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

vector<int> graph[200001];
int subordinate[200001];

int dfs(int x)
{
    if(subordinate[x])
        return subordinate[x];
    if(!graph[x].empty())
    {
        int employee=0;
        for(int i:graph[x])
        {
            employee+=dfs(i);
        }
        subordinate[x]=employee+1;
        return employee+1;
    }
    else
    {
        subordinate[x]=1;
        return 1;
    }
}

int main()
{
    quick
    int n,i,t;
    cin >> n;
    for(i=2;i<=n;i++)
    {
        cin >> t;
        graph[t].emplace_back(i);
    }
    for(i=1;i<=n;i++)
    {
        if(!subordinate[i])
            subordinate[i]=dfs(i);
    }
    for(i=1;i<=n;i++)
    {
        cout << subordinate[i]-1 << " ";
    }
    cout << "\n";
}
