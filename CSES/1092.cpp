#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,sse3,sse4,abm,mmx,tune=native,avx,avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define quick ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long

using namespace std;

int main()
{
    quick
    ll n,i,setsum;
    stack<ll> set1,set2;
    cin >> n;
    if((n*(n+1)>>1)&1)
        cout << "NO" << "\n";
    else
    {
        cout << "YES" << "\n";
        setsum=n*(n+1)/4;
        for(i=n;i>0;i--)
        {
            if(setsum>=i)
            {
                set1.push(i);
                setsum-=i;
            }
            else
                set2.push(i);
        }

        cout << set1.size() << "\n";
        while(!set1.empty())
        {
            cout << set1.top() << " ";
            set1.pop();
        }
        cout << "\n";

        cout << set2.size() << "\n";
        while(!set2.empty())
        {
            cout << set2.top() << " ";
            set2.pop();
        }
        cout << "\n";
    }
}
