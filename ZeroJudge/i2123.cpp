#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define RED "\e[1;31m"
#define RESET "\e[0m"
#define int long long

using namespace std;

void debug()
{
    cerr << "\n" << RESET;
}
template<class T,class ...U> void debug(T a,U ...b)
{
    cerr << RED << a << " ", debug(b...);
}

signed main()
{
    fastIO
    int n,k,x;
    stack<int> s;
    cin >> n;
    while(n--)
    {
        cin >> k;
        if(k==1)
        {
            cin >> x;
            s.push(x);
        }
        if(k==2)
        {
            if(s.empty())
                cout << "-1\n";
            else
                cout << s.top() << "\n";
        }
        if(k==3)
        {
            if(!s.empty())
                s.pop();
        }
    }
}