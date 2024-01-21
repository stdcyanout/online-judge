#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define RED "\e[1;31m"
#define RESET "\e[0m"
#define int long long
#define lowbit(x) (x)&(-(x))

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
    int n,p;
    string s;
    while(cin >> n && n)
    {
        s="";
        p=0;
        while(n)
        {
            s+=(n&1)+'0';
            if(n&1)
                ++p;
            n>>=1;
        }
        reverse(s.begin(),s.end());
        cout << "The parity of " << s << " is " << p << " (mod 2).\n";
    }
}