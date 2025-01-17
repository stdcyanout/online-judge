#include <bits/stdc++.h>
using namespace std;

void A (int n) { 
    for (int g = 1; g <= n; g++) {
        for (int j = 1; j <= n - g; j++)
            cout << " ";
        for (int j = 1; j <= 2 * g - 1; j++)
            cout << "*";
        cout << "\n";
    }
}

void B (int n) { 
    A(n);
    A(n);
}

void C (int n) { 
    for (int z = 1; z <= n; z++) {
        for (int g = 1; g <= z; g++) {
            for (int j = 1; j <= n - g; j++)
                cout << " ";
            for (int j = 1; j <= 2 * g - 1; j++)
                cout << "*";
            cout << "\n";
        }
    }    
}

void D (int n) {
    A(10 * n);
}

void E (int n) {
    for (int g = 1; g <= n; g++) {
        for (int j = 1; j <= n - g + 2; j++)
            cout << " ";
        for (int j = 1; j <= 2 * g - 1; j++)
            cout << "*";
        cout << "\n";
    }
    for (int z = 1; z <= 2 * n + 3; z++) {
        cout << "#";
    }
    cout << "\n";
}

void F (int n) {
    A(2 * n);
}

void G (int n) {
    A(3 * n);
}

void H (int n) {
    A(7 * n);
}

void I (int n) {
    A(4 * n - 1);
}

int main() {
    int t, n;
    char c;
    cin >> t;
    while(t--) {
        cin >> c >> n;
        if (c == 'A') A(n);
        else if (c == 'B') B(n);
        else if (c == 'C') C(n);
        else if (c == 'D') D(n);
        else if (c == 'E') E(n);
        else if (c == 'F') F(n);
        else if (c == 'G') G(n);
        else if (c == 'H') H(n);
        else if (c == 'I') I(n);
        cout << '\n';
    }    
}