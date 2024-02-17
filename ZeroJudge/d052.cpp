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

int solve(vector<int> v)
{
    vector<int> lis;
    for(int i:v)
    {
        if(lis.empty()||lis.back()<i)
            lis.push_back(i);
        else
            *lower_bound(lis.begin(),lis.end(),i)=i;
    }
    return lis.size();
}

signed main()
{
    fastIO
    int t,n,i;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<int> v(2*n);
        for(i=0;i<n;i++)
        {
            cin >> v[n+i];
            v[n-i-1]=v[n+i];
        }
        cout << solve(v) << "\n";
    }
}