#include <bits/stdc++.h>
using namespace std;
int id[1000000];
queue<int> q, group[1001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, t, x, cnt = 0;
    while(cin >> n)
    {
        cnt++;
        memset(id, 0, sizeof(id));
        q = queue<int>();
        for(int j = 1; j <= 1000; j++)
            group[j] = queue<int>();
        cout << "Line #" << cnt << "\n";
        for(int i = 1; i <= n; i++)
        {
            cin >> t;
            while(t--)
                cin >> x, id[x] = i;
        }
        string o;
        while(cin >> o && o != "STOP")
        {
            if(o == "ENQUEUE")
            {
                cin >> x;
                if(id[x] != 0)
                {
                    if(group[id[x]].empty())
                        q.push(-id[x]);
                    group[id[x]].push(x);
                }
                else
                    q.push(x);
            }
            else
            {
                if(q.front() < 0)
                {
                    cout << group[-q.front()].front() << "\n";
                    group[-q.front()].pop();
                    if(group[-q.front()].empty())
                        q.pop();
                }
                else
                {
                    cout << q.front() << "\n";
                    q.pop();
                }
            }
        }
    }
}