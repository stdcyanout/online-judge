#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
    long long i,j,k;
    vector<long long> u;
    for(i=1;i<1e18;i*=2)
    {
        for(j=1;i*j<1e18;j*=3)
        {
            for(k=1;i*j*k<1e18;k*=5)
            {
                u.emplace_back(i*j*k);
            }
        }
    }
    sort(u.begin(),u.end());

    long long t,n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << u[n] << "\n";
    }
}