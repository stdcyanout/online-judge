#include <bits/stdc++.h>
using namespace std;
int a[1001];
int main()
{
    int n;
    while(cin >> n && n)
    {
        while(cin >> a[0] && a[0])
        {
            stack<int> s;
            int cur = 0;
            for(int i = 1; i < n; i++)
                cin >> a[i];
            for(int i = 1; i <= n; i++)
            {
                s.push(i);
                while(!s.empty() && s.top() == a[cur])
                    s.pop(), cur++;
            }
            if(s.empty())
                cout << "Yes" << "\n";
            else
                cout << "No" << "\n";
        }
        cout << "\n";
    }
}