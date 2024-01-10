#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define RED "\e[1;31m"
#define RESET "\e[0m"
#define int long long
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair

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
    pii p[3];
    cin >> p[0].F >> p[0].S;
    cin >> p[1].F >> p[1].S;
    cin >> p[2].F >> p[2].S;
    sort(p,p+3);
    if(p[0].S>p[1].F || p[1].S>p[2].F)
        cout << "QQ" << "\n";
    else
        cout << "Happy" << "\n";
}