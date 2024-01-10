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

vector<bool> v;

signed main()
{
    fastIO
    int n;
    while(cin >> n)
    {
        v.clear();
        do
        {
            v.emplace_back(n&1);
            n>>=1;
        }while(n);
        reverse(v.begin(),v.end());
        for(bool i:v)
        {
            cout << i;
        }
        cout << "\n";
    }
}