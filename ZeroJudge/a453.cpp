#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,a,b,c,d,sqrtd;
    cin >> n;
    while(n--)
    {
        cin >> a >> b >> c;
        d=b*b-4*a*c;
        sqrtd=round(sqrt(d));
        if(sqrtd*sqrtd==d)
            cout << "Yes" << "\n";
        else
            cout << "No" << "\n";
    }
}
