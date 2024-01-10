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

vector<int> v;

signed main()
{
    fastIO
    int m,n,i,j;
    for(i=1;i<=100000000;i*=2)
    {
        for(j=1;i*j<=100000000;j*=5)
        {
            v.emplace_back(i*j);
        }
    }
    sort(v.begin(),v.end());
    cin >> m;
    while(m--)
    {
        cin >> n;
        cout << upper_bound(v.begin(),v.end(),n)-v.begin()-1 << "\n";
    }
}