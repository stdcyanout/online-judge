#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int a[50];

int gcd(int x,int y)
{
    if(!(x%y))
        return y;
    return gcd(y,x%y);
}

int main()
{
    fastIO
    int n,i,j,t,tp;
    double pi;
    while(cin >> n)
    {
        if(n==0)
            break;
        t=n*(n-1)/2;
        tp=0;
        for(i=0;i<n;i++)
            cin >> a[i];
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(gcd(a[i],a[j])==1)
                    tp++;
            }
        }
        if(tp)
        {
            pi=sqrt(6.0*t/tp);
            cout << setiosflags(ios::fixed) << setprecision (6) << pi << "\n";
        }
        else
            cout << "No estimate for this data set.\n";
    }
}
