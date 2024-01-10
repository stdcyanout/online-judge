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
    string s;
    int sum,tmp;
    while(getline(cin,s))
    {
        sum=0;
        stringstream ss;
        ss << s;
        while(ss >> tmp)
        {
            sum+=tmp;
        }
        cout << sum << "\n";
    }
}