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

int ind[2][10]={{0,2,4,6,8,1,3,5,7,9},{0,1,2,3,4,5,6,7,8,9}};

bool isvalid(string s)
{
    int solve=0,i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            solve+=ind[j&1][(int)(s[5*i+j]-'0')];
        }
    }
    return !(solve%10);
}

signed main()
{
    fastIO
    int n;
    string s;
    cin >> n;
    cin.ignore();
    while(n--)
    {
        getline(cin,s);
        if(isvalid(s))
            cout << "Valid\n";
        else
            cout << "Invalid\n";
    }
}