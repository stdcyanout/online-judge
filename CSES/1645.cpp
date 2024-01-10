#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pii pair<int,int>
#define mp make_pair
#define F first
#define S second

using namespace std;

int main()
{
    fastIO
    int n,x,i;
    stack<pii> monostack;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> x;
        while(!monostack.empty() && monostack.top().S>=x)
            monostack.pop();

        if(monostack.empty())
            cout << 0 << " ";
        else
            cout << monostack.top().F << " ";

        monostack.push(mp(i,x));
    }
}
