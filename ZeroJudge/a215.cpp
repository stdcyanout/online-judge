#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define RED "\e[1;31m"
#define RESET "\e[0m"

using namespace std;

void debug()
{
    cerr << "\n" << RESET;
}
template<class T,class ...U> void debug(T a,U ...b)
{
    cerr << RED << a << " ", debug(b...);
}

int main()
{
    //fastIO
    long long n,m,sum,cnt;
    while(cin >> n >> m)
    {
        sum=cnt=0;
        do
        {
            sum+=n;
            ++cnt;
            ++n;
        }
        while(sum<=m);
        cout << cnt << "\n";
    }
}