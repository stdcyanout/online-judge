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

set<string> sset;
signed main()
{
    fastIO
    string s;
    while(getline(cin,s))
    {
        if(sset.find(s)!=sset.end())
            cout << "YES\n";
        else
        {
            sset.insert(s);
            cout << "NO\n";
        }
    }
}