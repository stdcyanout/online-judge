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

bitset<100001> b,tmp;
vector<int> v;

signed main()
{
    fastIO
    int n,x,i;
    cin >> n;
    while(n--)
    {
        cin >> x;
        tmp=b;
        tmp<<=x;
        b|=tmp;
        b[x]=1;
    }
    for(i=1;i<=100000;i++)
    {
        if(b[i]==1)
            v.emplace_back(i);
    }
    cout << v.size() << "\n";
    for(int t:v)
        cout << t << " ";
}