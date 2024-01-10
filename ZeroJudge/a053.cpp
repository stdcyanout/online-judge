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

int score(int n)
{
    if(n>40)
        return 100;
    if(n>20)
        return score(n-1)+1;
    if(n>10)
        return score(n-1)+2;
    return n*6;
}

signed main()
{
    fastIO
    int n;
    cin >> n;
    cout << score(n) << "\n";
}