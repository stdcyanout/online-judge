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

bool cmp(string a,string b)
{
    if(a[0]=='-')
    {
        if(b[0]=='-')
        {
            string c(a,1,a.length()-1);
            string d(b,1,b.length()-1);
            return cmp(d,c);
        }
        else
            return 1;
    }
    else if(b[0]=='-')
        return 0;
    else
    {
        if(a.length()==b.length())
        {
            reverse(a.begin(),a.end());
            reverse(b.begin(),b.end());
            return a<b;
        }
        return a.length()<b.length();
    }
}

signed main()
{
    fastIO
    int n;
    string s;
    while(cin >> n)
    {
        vector<string> v;
        while(n--)
        {
            cin >> s;
            v.push_back(s);
        }
        sort(v.begin(),v.end(),cmp);
        for(string t:v)
        {
            cout << t << "\n";
        }
    }
}