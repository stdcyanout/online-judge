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
    int n,t,i;
    while(cin >> n)
    {
        vector<int> num[10];
        while(n--)
        {
            cin >> t;
            num[t%10].emplace_back(t);
        }
        for(i=0;i<10;i++)
        {
            sort(num[i].begin(),num[i].end(),greater<int>());
            for(int j:num[i])
                cout << j << " ";
        }
        cout << "\n";
    }
}