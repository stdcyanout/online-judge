#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,d,num=0,cost=0;
    cin >> n >> d;
    int a[3];
    while(n--)
    {
        cin >> a[0] >> a[1] >> a[2];
        sort(a,a+3);
        if(a[2]-a[0]>=d)
        {
            num+=1;
            cost+=(a[0]+a[1]+a[2])/3;
        }
    }
    cout << num << " " << cost << endl;

}
