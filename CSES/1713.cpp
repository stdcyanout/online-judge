#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,x,xprime,d,i;
    cin >> n;
    while(n--)
    {
        cin >> x;
        xprime=sqrt(x);
        d=0;
        for(i=1;i<=xprime;i++)
            if(!(x%i))d++;
        d=d*2;
        if(xprime*xprime==x)
            d--;
        cout << d << "\n";
    }
}
