#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define quick ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

bitset<1000000001> b;

int main()
{
    int n,x,cnt=0;
    cin >> n;
    while(n--)
    {
        cin >> x;
        if(!b[x])
            cnt++;
        b[x]=1;
    }
    cout << cnt << "\n";
}
