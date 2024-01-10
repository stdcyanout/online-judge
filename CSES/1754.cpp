#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define quick ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int main()
{
    quick
    int t,a,b;
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        if(a<b)
            swap(a,b);
        if(a>2*b)
            cout << "NO" << "\n";
        else
        {
            if((a-b*2)%3)
                cout << "NO" << "\n";
            else
                cout << "YES" << "\n";
        }
    }
}
