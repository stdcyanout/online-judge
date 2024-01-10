#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a,a+3);
    cout << a[0] << " " << a[1] << " " << a[2] << "\n";
    if(a[0]+a[1]<=a[2])
        cout << "No" << "\n";
    else if(a[0]*a[0]+a[1]*a[1]<a[2]*a[2])
        cout << "Obtuse" << "\n";
    else if(a[0]*a[0]+a[1]*a[1]==a[2]*a[2])
        cout << "Right" << "\n";
    else if(a[0]*a[0]+a[1]*a[1]>a[2]*a[2])
        cout << "Acute" << "\n";
}
