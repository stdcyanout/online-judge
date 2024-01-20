#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define RED "\e[1;31m"
#define RESET "\e[0m"
#define int long long
#define eps 1e-6

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
    double a,b,c,d,e,f,x,y;
    cin >> a >> b >> c >> d >> e >> f;
    if(abs(a*e-b*d)>eps)
    {
        x=(c*e-b*f)/(a*e-b*d);
        y=(a*f-c*d)/(a*e-b*d);
        cout << fixed << setprecision(2) << "x=" << x << "\ny=" << y << "\n";
    }
    else
    {
        if(abs(a*f-c*d)<eps)
            cout << "Too many\n";
        else
            cout << "No answer\n";
        return 0;
    }
}