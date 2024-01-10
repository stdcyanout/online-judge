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
    int a,b,c,A[5],B[5],i;
    cin >> a >> b >> c;
    for(i=0;i<5;i++)
    {
        cin >> A[i];
    }
    for(i=0;i<5;i++)
    {
        cin >> B[i];
    }
    int sum=0;
    bool db=1;
    for(i=0;i<5;i++)
    {
        if(A[i]==a || A[i]==b)
            sum+=B[i];
        if(A[i]==c)
        {
            sum-=B[i];
            db=0;
        }
    }
    sum+=db*sum;
    if(sum<0)
        cout << 0 << "\n";
    else
        cout << sum << "\n";
}