#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int i;
    int n,m,s,t,a,b;
    while(cin >> n >> m)
    {
        vector<int> side[n+1];

        for(i=0;i<m;i++)
        {
            cin >> s >> t;
            side[s].push_back(t);
        }

        cin >> a >> b;

        bool ans=0;
        queue<int> q;
        q.push(a);
        while(!q.empty())
        {
            i=q.front();
            q.pop();
            if(i==b)
            {
                ans=1;
                break;
            }
            for(int j:side[i])
                q.push(j);
        }
        if(ans)
            cout << "Yes!!!\n";
        else
            cout << "No!!!\n";
    }
}
