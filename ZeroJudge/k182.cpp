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

int main()
{
    fastIO
    int n,t,sum=0,ave;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> t;
        sum+=t;
    }
    ave=round(double(sum*100)/n);
    if(ave%100)
    {
        if(ave%10)
            cout << ave/100 << "." << ave%100 << "\n";
        else
            cout << ave/100 << "." << ave%100/10 << "\n";
    }
    else
        cout << ave/100 << "\n";
}