#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define quick ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long

using namespace std;

int main()
{
    quick
    ll n,p,t,i,minimum=LONG_LONG_MAX;
    queue<ll> q;
    q.push(0);
    cin >> n;
    while(n--)
    {
        cin >> p;
        t=q.size();
        while(t--)
        {
            i=q.front();
            q.pop();
            q.push(i+p);
            q.push(i-p);
        }
    }

    while(!q.empty())
    {
        if(q.front()>=0)
            minimum=min(q.front(),minimum);
        q.pop();
    }

    cout << minimum << "\n";
}
