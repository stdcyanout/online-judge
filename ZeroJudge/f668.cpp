#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i;
    int n,m,s,t;
    cin >> n >> m;
    set<int> side[n+1];
    for(i=0;i<m;i++)
    {
        cin >> s >> t;
        side[s].insert(t);
        side[t].insert(s);
    }
    for(i=1;i<=n;i++)
    {
        cout << i << "\:";
        for(int j:side[i])
            cout << " " << j;
        cout << "\n";
    }
}
