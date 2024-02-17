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

string nospace(string s)
{
    string t="";
    for(char c:s)
    {
        if(c!=' ')
            t+=c;
    }
    return t;
}

signed main()
{
    fastIO
    int n,i;
    string a,b;
    cin >> n;
    cin.ignore();
    for(i=1;i<=n;i++)
    {
        getline(cin,a);
        getline(cin,b);
        if(a==b)
            cout << "Case " << i << ": Yes\n";
        else if(nospace(a)==b)
            cout << "Case " << i << ": Output Format Error\n";
        else
            cout <<  "Case " << i << ": Wrong Answer\n";
    }
}