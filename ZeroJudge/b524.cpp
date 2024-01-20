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

vector<int> v[2];

signed main()
{
    fastIO
    int i;
    string s;
    while(cin >> s)
    {
        v[0].clear();
        v[1].clear();
        for(i=0;i<s.length();i+=3)
        {
            v[0].push_back(i);
        }
        for(i=0;i<s.length();i++)
        {
            if(s[i]=='y')
            v[1].push_back(i);
        }
        int ans=0;
        for(i=0;i<v[0].size();i++)
        {
            ans+=abs(v[0][i]-v[1][i]);
        }
        cout << ans << "\n";
    }
}