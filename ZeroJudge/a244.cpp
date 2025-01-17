#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        switch(a)
        {
        case 1:
            cout << b + c << "\n";
            break;
        case 2 :
            cout << b - c << "\n";
            break;
        case 3:
            cout << b * c << "\n";
            break;
        case 4:
            cout << b / c << "\n";
        }
    }
}