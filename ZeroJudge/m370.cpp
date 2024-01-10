#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define quick ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    quick

    int x,n,t,lcnt=0,rcnt=0,maxl=INT_MIN,minl=INT_MAX;
    cin >> x >> n;
    while(n--)
    {
        cin >> t;
        if(t>x)
        {
            rcnt+=1;
            maxl=max(maxl,t);
        }
        else
        {
            lcnt+=1;
            minl=min(minl,t);
        }
    }

    if(rcnt>lcnt)
        cout << rcnt << " " << maxl;
    else
        cout << lcnt << " " << minl;
}
