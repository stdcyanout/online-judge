#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if(a >= b && a > c)
        swap(a, c);
    else if(b > a && b > c)
        swap(b, c);
    if(a > b)
        swap(a, b);
    cout << a << " " << b << " " << c << "\n";
    if(a + b <= c)
        cout << "No\n";
    else if(a * a + b * b < c * c)
        cout << "Obtuse\n";
    else if(a * a + b * b == c * c)
        cout << "Right\n";
    else
        cout << "Acute\n";
}