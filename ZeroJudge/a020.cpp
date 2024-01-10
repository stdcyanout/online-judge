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

int ind[]={1,10,19,28,37,46,55,64,39,73,82,2,11,20,48,29,38,47,56,65,74,83,21,3,12,30};

signed main()
{
    fastIO
    char c;
    int check=0;
    cin >> c;
    check+=ind[(int)(c-'A')];
    for(int i=8;i>0;i--)
    {
        cin >> c;
        check+=i*((int)(c-'0'));
    }
    cin >> c;
    check+=(int)(c-'0');
    if(check%10)
        cout << "fake\n";
    else
        cout << "real\n";
}