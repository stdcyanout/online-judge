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

vector<int> ugly;

signed main()
{
    fastIO
    int i,j,k;
    for(i=1;i<1e18;i*=2)
    {
        for(j=1;i*j<1e18;j*=3)
        {
            for(k=1;i*j*k<1e18;k*=5)
            {
                ugly.emplace_back(i*j*k);
            }
        }
    }
    sort(ugly.begin(),ugly.end());

    int t,n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << ugly[n-1] << "\n";
    }
}