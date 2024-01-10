#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int a[t][5];
    int i;
    for(i=0;i<t;i++)
    {
        cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];
        if(a[i][2]-a[i][1]==a[i][1]-a[i][0])
            a[i][4]=a[i][3]+a[i][1]-a[i][0];
        if(a[i][2]/a[i][1]==a[i][1]/a[i][0])
            a[i][4]=a[i][3]*a[i][1]/a[i][0];
    }
    for(i=0;i<t;i++)
    {
        for(int j:a[i])
            cout << j << " ";
        cout << endl;
    }
}
