#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    n-=1;
    int d,maxd=INT_MIN,mind=INT_MAX;
    int x0,y0,x,y;
    cin >> x0 >> y0;
    while(n--)
    {
        cin >> x >> y;
        d=abs(x-x0)+abs(y-y0);
        maxd=max(maxd,d);
        mind=min(mind,d);
        x0=x;
        y0=y;
    }
    cout << maxd << " " << mind << "\n";
}
