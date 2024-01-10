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

int a[14];

string s[]={
    "None\n",
    "A\n",
    "B\n",
    "AB\n",
    "C\n",
    "AC\n",
    "BC\n",
    "ABC\n",
};

// 1  2  3  4  5  6  7
// 0  1  2  3  4  5  6
// 7  8  9  10 11 12 13

signed main()
{
    fastIO
    int n,ind;
    cin >> n;
    while(n--)
    {
        ind=0;
        for(int i=0;i<14;i++)
            cin >> a[i];
        
        if(a[1]==a[3]||a[1]!=a[5]||a[8]==a[10]||a[8]!=a[12])
            ind+=1;

        if(a[6]==0||a[13]==1)
            ind+=2;

        if(a[1]==a[8]||a[3]==a[10]||a[5]==a[12])
            ind+=4;

        cout << s[ind];
    }
}