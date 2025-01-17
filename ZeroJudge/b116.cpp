#include <bits/stdc++.h>
using namespace std;
bitset<100000> b;
int main() {
    int m, n, i, j, t;
    while (cin >> m >> n) {
        for (i = 0; i < m; i++) {
            b.reset();
            b[50000] = 1;
            for(j = 0; j < n; j++) {
                cin >> t;
                b = (b >> t) | (b << t);
            }
            if (b[50000])
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
}