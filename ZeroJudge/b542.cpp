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

int a[100000],n;

inline bool fnd(int t)
{
    int l=0,r=1;
    while(l<n && r<n)
    {
        if(a[r]-a[l]==t)
            return true;
        else if(a[r]-a[l]>t)
            ++l;
        else
            ++r;
    }
    return false;
}

signed main()
{
    fastIO
    int q,i;
    cin >> n >> q;
    for(i=0;i<n;i++)
    {
        cin >> a[i];
    }
    sort(a,a+n);
    while(q--)
    {
        cin >> i;
        if(fnd(i))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}