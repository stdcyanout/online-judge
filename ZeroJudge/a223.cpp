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

vector<int> factor(int n)
{
    vector<int> tmp,v;
    int i;
    for(i=1;i*i<=n;i++)
    {
        if(!(n%i))
        {
            v.emplace_back(i);
            if(i*i<n)
                tmp.emplace_back(n/i);
        }
    }
    for(i=tmp.size()-1;i>=0;i--)
    {
        v.emplace_back(tmp[i]);
    }
    return v;
}

bool cmp(string& s,int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<s.length();j+=n)
        {
            if(s[i+j]!=s[i])
                return 0;
        }
    }
    return 1;
}

signed main()
{
    fastIO
    string s;
    while(cin >> s && s!=".")
    {
        vector<int> v=factor(s.length());
        for(int i:v)
        {
            if(cmp(s,i))
            {
                cout << s.length()/i << "\n";
                break;
            }
        }
    }
}