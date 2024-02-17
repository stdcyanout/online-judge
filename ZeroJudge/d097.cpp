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

int a[3000];

bool isjolly(int n)
{
    int i,x,y;
    for(i=0;i<n;i++)
        a[i]=0;
    cin >> x;
    for(i=1;i<n;i++)
    {
        cin >> y;
        if(abs(x-y)>=n)
            return 0;
        else
            ++a[abs(x-y)];
        x=y;
    }
    if(a[0])
        return 0;
    for(i=1;i<n;i++)
    {
        if(a[i]!=1)
            return 0;
    }
    return 1;
}

signed main()
{
    fastIO
    int n,i;
    while(cin >> n)
    {
        if(isjolly(n))
            cout << "Jolly\n";
        else
            cout << "Not jolly\n";
    }
}