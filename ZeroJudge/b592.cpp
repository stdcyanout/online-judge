#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define quick ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define MOD 1000000007

using namespace std;

long long fast_power(int n)
{
    if(n==0)
        return 1;
    long long res = fast_power(n>>1)%MOD;
    if(n&1)
        return res*res%MOD*2%MOD;
    return res*res%MOD;
}

long long hanoi(vector<int> a,int n)
{
    if(a.size()==1)
    {
        if(a[0]==n)
            return 0;
        else
            return 1;
    }
    while(a[a.size()-1]==n)
    {
        a.pop_back();
        if(a.size()==1)
        {
            if(a[0]==n)
                return 0;
            else
                return 1;
        }
    }
    n=6-n-a[a.size()-1];
    a.pop_back();
    return (hanoi(a,n)+fast_power(a.size()))%MOD;
}

int main()
{
    quick
    int n,x,i;
    vector<int> a,b;
    while(cin >> n)
    {
        if(!n)
            break;
        for(i=0;i<n;i++)
        {
            cin >> x;
            a.push_back(x);
        }
        for(i=0;i<n;i++)
        {
            cin >> x;
            b.push_back(x);
        }
        if(a.size()==1)
        {
            if(a[0]==b[0])
            {
                cout << 0 << "\n";
                goto f;
            }
            else
            {
                cout << 1 << "\n";
                goto f;
            }
        }
        while(a[a.size()-1]==b[b.size()-1])
        {
            if(a.size()==1)
            {
                cout << 0 << "\n";
                goto f;
            }
            a.pop_back();
            b.pop_back();
        }
        i=6-a[a.size()-1]-b[b.size()-1];
        a.pop_back();
        b.pop_back();
        cout << (hanoi(a,i)+hanoi(b,i)+1)%MOD << "\n";
        f:a.clear();
        b.clear();
    }
}
