#include <bits/stdc++.h>
using namespace std;
queue<int> q;
int main()
{
    int n, k, x;
    cin >> n;
    while(n--)
    {
        cin >> k;
        if(k == 1)
        {
            cin >> x;
            q.push(x);
        }
        else if(k == 2)
        {
            if(q.empty())
                cout << -1 << "\n";
            else
                cout << q.front() << "\n";
        }
        else if(k == 3)
        {
            if(!q.empty())
                q.pop();
        }
    }
}