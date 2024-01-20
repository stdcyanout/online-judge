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

string s[]={"","1","21","321","4321","54321","654321","7654321","87654321"};

signed main()
{
    fastIO
    int n;
    while(cin >> n)
    {
        string sp=s[n];
        do
            cout << sp << "\n";
        while(prev_permutation(sp.begin(), sp.end()));
    }
}