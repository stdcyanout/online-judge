#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a,b,c,d;
    cin >> a >> b >> c;
    d=b*b-4*a*c;
    if(d>0)
        cout << "Two different roots x1=" << (-b+sqrt(d))/(2*a) << " , x2=" <<  (-b-sqrt(d))/(2*a) << "\n";
    else if(d==0)
        cout << "Two same roots x=" << (-b)/(2*a) << "\n";
    else
        cout << "No real root" << "\n";
}
