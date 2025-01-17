#include <bits/stdc++.h>
using namespace std;
stack<int> s;
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
            s.push(x);
        }
        else if(k == 2)
        {
            if(s.empty())
                cout << -1 << "\n";
            else
                cout << s.top() << "\n";
        }
        else if(k == 3)
        {
            if(!s.empty())
                s.pop();
        }
    }
}