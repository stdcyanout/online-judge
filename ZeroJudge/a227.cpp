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

void hanoi(int n,int a,int b)
{
    if(n)
    {
        hanoi(n-1,a,3-a-b);
        cout << "Move ring " << n << " from " << char('A'+a) << " to " << char('A'+b) << "\n";
        hanoi(n-1,3-a-b,b);
    }
}

signed main()
{
    fastIO
    int n;
    while(cin >> n)
    {
        hanoi(n,0,2);
        cout << "\n";
    }
}