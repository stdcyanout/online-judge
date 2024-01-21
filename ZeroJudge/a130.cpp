#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define RED "\e[1;31m"
#define RESET "\e[0m"
#define int long long
#define psi pair<string,int>
#define F first
#define S second

using namespace std;

void debug()
{
    cerr << "\n" << RESET;
}
template<class T,class ...U> void debug(T a,U ...b)
{
    cerr << RED << a << " ", debug(b...);
}

bool cmp(psi a, psi b)
{
    return a.S>b.S;
}

signed main()
{
    fastIO
    int n,i,t;
    cin >> n;
    for(t=1;t<=n;t++)
    {
        vector<psi> v(10);
        for(i=0;i<10;i++)
            cin >> v[i].F >> v[i].S;
        sort(v.begin(),v.end(),cmp);
        cout << "Case #" << t << ":\n";
        for(i=0;i<10;i++)
        {
            if(v[i].S<v[0].S)
                break;
            cout << v[i].F << "\n";
        }
    }
}