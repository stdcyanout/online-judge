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
    char c[8];
    cin >> c[0] >> c[1] >> c[2] >> c[3];
    int n,a,b;
    cin >> n;
    while(n--)
    {
        a=b=0;
        cin >> c[4] >> c[5] >> c[6] >> c[7];

        if(c[0]==c[4])++a;
        else if(c[1]==c[4] || c[2]==c[4] || c[3]==c[4])++b;

        if(c[1]==c[5])++a;
        else if(c[0]==c[5] || c[2]==c[5] || c[3]==c[5])++b;

        if(c[2]==c[6])++a;
        else if(c[0]==c[6] || c[1]==c[6] || c[3]==c[6])++b;

        if(c[3]==c[7])++a;
        else if(c[0]==c[7] || c[1]==c[7] || c[2]==c[7])++b;

        cout << a << "A" << b << "B" << "\n";
    }
}