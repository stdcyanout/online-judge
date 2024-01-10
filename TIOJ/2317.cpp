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

vector<int> v;

signed main()
{
    fastIO
    string s;
    int n,y,d;
    cin >> n;
    while(n--)
    {
        cin >> s >> y >> d;
        v.emplace_back(y*100+d);
    }
    sort(v.begin(),v.end());
    cin >> y >> d;
    auto it=upper_bound(v.begin(),v.end(),y*100+d);
    cout << it-v.begin() << "\n";
}