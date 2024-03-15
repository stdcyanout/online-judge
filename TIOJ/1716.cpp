//International Olympiad in Informatics Gold Medal
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define RED "\e[1;31m"
#define RESET "\e[0m"
#define int int64_t
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

bool check(int a,int b,int c)
{
    int d=b*b-4*a*c;
    if(d<0)
        return 0;
    int sqrtd=sqrt(d)+eps;
    if(sqrtd*sqrtd==d)
        return 1;
    return 0;
}

signed main()
{
    fastIO
    int m,a,b,c;
    cin >> m;
    while(m--)
    {
        cin >> a >> b >> c;
        if(check(a,b,c))
            cout << "Yes" << "\n";
        else
            cout << "No" << "\n";
    }
}