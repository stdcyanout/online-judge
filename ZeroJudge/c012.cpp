#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define RED "\e[1;31m"
#define RESET "\e[0m"
#define int long long
#define pii pair<int,int>
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

bool cmp(pii a, pii b)
{
    if(a.S==b.S)
        return a.F>b.F;
    return a.S<b.S;
}

signed main()
{
    fastIO
    string s;
    int i;
    while(getline(cin,s))
    {
        int a[128];
        vector<pii> v;
        for(i=0;i<128;i++)
            a[i]=0;
        for(i=0;i<s.length();i++)
        {
            ++a[(int)(s[i])];
        }
        for(i=32;i<127;i++)
        {
            if(a[i])
                v.push_back({i,a[i]});
        }
        sort(v.begin(),v.end(),cmp);
        for(pii p:v)
            cout << p.F << " " << p.S << "\n";
        cout << "\n";
    }
}