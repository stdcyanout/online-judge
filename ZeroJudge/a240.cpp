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

int a[]={0,5,8,8,2,3,5,2,9,4,1,1,7,6,4,7};
int b[]={0,5,13,21,23,26,31,33,42,46,47,48,55,61,65,72};

signed main()
{
    fastIO 
    int t,n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << a[(n-1)%16] << " " << (n-1)/16*72+b[(n-1)%16] << "\n";
    }
}