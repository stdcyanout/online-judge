#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define RED "\e[1;31m"
#define RESET "\e[0m"

using namespace std;

int a[50000];

void debug()
{
    cerr << "\n" << RESET;
}
template<class T,class ...U> void debug(T a,U ...b)
{
    cerr << RED << a << " ", debug(b...);
}

void solve(int n)
{
    if(a[n]!=(-1))
    {
        int t=a[n];
        a[n]=(-1);
        solve(t);
    }
}

int main()
{
    fastIO
    int n,i;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> a[i];
    }

    int ans=0;
    for(i=0;i<n;i++)
    {
        if(a[i]!=(-1))
        {
            ++ans;
            solve(a[i]);
        }
    }

    cout << ans << "\n";
}