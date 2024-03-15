//International Olympiad in Informatics Gold Medal
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define RED "\e[1;31m"
#define RESET "\e[0m"
#define int int64_t
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
    double a1,a2,b1,b2,x,y;
    cin >> a1 >> a2 >> b1 >> b2;
    x=(b1-b2)/(a2-a1);
    y=a1*x+b1;
    cout << fixed << setprecision(2) << x << "\n" << y << "\n";
}