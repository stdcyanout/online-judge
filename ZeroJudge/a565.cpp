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
    int n,i,ans;
    string s;
    cin >> n;
    while(n--)
    {
        ans=0;
        stack<char> stk;
        cin >> s;
        for(i=0;i<s.length();i++)
        {
            if(s[i]=='p')
            {
                stk.push('p');
            }

            if(s[i]=='q')
            {
                if(!stk.empty() && stk.top()=='p')
                {
                    ans++;
                    stk.pop();
                }
            }
        }
        cout << ans << "\n";
    }
}