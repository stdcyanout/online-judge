#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a1, b1, c1, a2, b2, c2, n;
	cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2 >> n;
	if(a1 + a2 >= 0)
    {
        int r1 = a1 * n * n + b1 * n + c1 + c2; // x1 = n
        int r2 = a2 * n * n + b2 * n + c1 + c2; // x1 = 0
        if(r1 > r2) r2 = r1;
        cout << r2 << "\n";
    }
    else
    {
        double x = 1.0 * (2 * a2 * n - b1 + b2) / (2 * a1 + 2 * a2);
        int p = round(x);
        if(p < 0) p = 0;
        if(p > n) p = n;
        cout << (a1 + a2) * p * p + (b1 - b2 - 2 * a2 * n) * p + a2 * n * n + b2 * n + c1 + c2 << "\n";
    }
}