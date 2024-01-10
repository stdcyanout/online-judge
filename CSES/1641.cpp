#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define quick ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pii pair<int,int>
#define mp make_pair
#define F first
#define S second

using namespace std;

int main()
{
    quick
    int n,x,i,t,l,r;
    cin >> n >> x;

    vector<pii> a;
    for(i=0;i<n;i++)
    {
        cin >> t;
        a.push_back(mp(t,i+1));
    }

    sort(a.begin(),a.end());

    for(i=0;i<n-2;i++)
    {
        l=i+1;
        r=n-1;
        while(l<r)
        {
            if(a[i].F+a[l].F+a[r].F==x)
            {
                cout << a[i].S << " " << a[l].S << " " << a[r].S << "\n";
                return 0;
            }
            else if(a[i].F+a[l].F+a[r].F<x)
                l++;
            else
                r--;
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
