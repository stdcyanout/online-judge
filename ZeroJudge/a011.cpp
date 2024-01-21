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
    string s,tmp;
    int cnt,i;
    while(getline(cin,s))
    {
        for(i=0;i<s.length();i++)
        {
            if(!isalpha(s[i]))
                s[i]=' ';
        }
        stringstream ss;
        ss << s;
        cnt=0;
        while(ss >> tmp)
            ++cnt;
        cout << cnt << "\n";
    }
}