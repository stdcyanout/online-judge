#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define RED "\e[1;31m"
#define RESET "\e[0m"
#define int long long
#define gcd __gcd

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
    int n,tmp,i,j,maxgcd;
    string s;
    vector<int> v;
    cin >> n;
    cin.ignore();
    while(n--)
    {
        maxgcd=0;
        stringstream ss;
        v.clear();
        getline(cin,s);
        ss << s;
        while(ss >> tmp)
        {
            v.push_back(tmp);
        }
        for(i=0;i<v.size();i++)
        {
            for(j=i+1;j<v.size();j++)
            {
                maxgcd=max(gcd(v[i],v[j]),maxgcd);
            }
        }
        cout << maxgcd << "\n";
    }
}