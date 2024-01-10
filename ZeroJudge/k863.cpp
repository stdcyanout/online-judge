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
    map<string,int> ind=
    {
        {"ShunZhi", 1644},
        {"KangXi", 1662},
        {"YongZheng", 1723},
        {"QianLong", 1736},
        {"JiaQing", 1796},
        {"DaoGuang", 1821},
        {"XianFeng", 1851},
        {"TongZhi", 1862},
        {"GuangXu", 1875},
        {"XuanTong", 1909}
    };
    string s;
    int n;
    cin >> s >> n;
    cout << ind[s]+n-1 << "\n";
}