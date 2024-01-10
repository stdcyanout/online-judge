#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,i,times;
    cin >> n;
    for(i=2;i<=n;i++)
    {
        times=0;
        while(n%i==0)
        {
            n/=i;
            times++;
        }
        if(times>1)
            cout << i << "^" << times;
        else if(times==1)
            cout << i;
        if(n!=1&&times>0)
            cout << " * ";
    }
}
