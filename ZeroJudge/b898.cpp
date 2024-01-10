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
    int n;
    string s[3];
    pair<int,string> p[3];
    cin >> n;
    while(n--)
    {
        cin >> s[0] >> s[1] >> s[2];
        p[0]={s[0].length(),s[0]};
        p[1]={s[1].length(),s[1]};
        p[2]={s[2].length(),s[2]};
        sort(p,p+3);
        cout << p[2].second << "\n";
    }
}