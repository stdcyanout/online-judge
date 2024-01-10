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
    int n,k,t,i;
    vector<int> v;
    cin >> n >> k;
    while(n--)
    {
        cin >> t;
        v.emplace_back(t);
    }

    while(k--)
    {
        cin >> t;
        auto it=lower_bound(v.begin(),v.end(),t);
        if(*it==t)
        {
            cout << (it-v.begin())+1 << "\n";
        }
        else
        {
            cout << 0 << "\n";
        }
    }
}