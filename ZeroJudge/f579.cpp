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
    int a,b,n,tmp,counta,countb,cnt=0;
    string s;
    cin >> a >> b >> n;
    cin.ignore();
    while(n--)
    {
        counta=0;
        countb=0;
        getline(cin,s);
        stringstream ss;
        ss << s;
        while(ss >> tmp)
        {
            if(tmp==a)
                ++counta;
            if(tmp==-a)
                --counta;
            if(tmp==b)
                ++countb;
            if(tmp==-b)
                --countb;
        }
        cnt+=counta>0&&countb>0;
    }
    cout << cnt << "\n";
}