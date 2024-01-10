#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define RED "\e[1;31m"
#define RESET "\e[0m"

using namespace std;

void debug()
{
    cerr << "\n" << RESET;
}
template<class T,class ...U> void debug(T a,U ...b)
{
    cerr << RED << a << " ", debug(b...);
}

void output(string s,int n)
{
    while(n--)
        cout << s;
}

int main()
{
    fastIO
    int n,i,j;
    cin >> n;
    for(i=0;i<n;i++)
    {
        output("_",n-i-1);
        output("*",2*i+1);
        output("_",n-i-1);
        cout << "\n";
    }
}