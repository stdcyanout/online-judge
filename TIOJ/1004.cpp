#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int josephu(int n)
{
    if(n==1)
        return 0;
    return (josephu(n-1)+2)%n;
}

int main()
{
    fastIO;
    int n;
    cin >> n;
    cout << josephu(n)+1 << "\n";
}
