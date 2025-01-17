#include <bits/stdc++.h>
using namespace std;
vector<int> v[1000001];
int main()
{
    int n, k, a, b;
    cin >> n >> k;
    while(k--)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i = 1; i <= n; i++)
    {
        sort(v[i].begin(), v[i].end());
        for(int j = 0; j < v[i].size(); j++)
            cout << v[i][j] << " \n"[j == v[i].size() - 1];
        if(v[i].size() == 0) cout << "\n";
    }
}