#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    fastIO
    int t;
    while(cin >> t)
    {
        t%=20;
        switch(t)
        {
        case 0:
            cout << "(10,5)\n";
            break;
        case 1:
            cout << "(15,6)\n";
            break;
        case 2:
            cout << "(15,12)\n";
            break;
        case 3:
            cout << "(12,15)\n";
            break;
        case 4:
            cout << "(6,15)\n";
            break;
        case 5:
            cout << "(5,10)\n";
            break;
        case 6:
            cout << "(6,5)\n";
            break;
        case 7:
            cout << "(12,5)\n";
            break;
        case 8:
            cout << "(15,8)\n";
            break;
        case 9:
            cout << "(15,14)\n";
            break;
        case 10:
            cout << "(10,15)\n";
            break;
        case 11:
            cout << "(5,14)\n";
            break;
        case 12:
            cout << "(5,8)\n";
            break;
        case 13:
            cout << "(8,5)\n";
            break;
        case 14:
            cout << "(14,5)\n";
            break;
        case 15:
            cout << "(15,10)\n";
            break;
        case 16:
            cout << "(14,15)\n";
            break;
        case 17:
            cout << "(8,15)\n";
            break;
        case 18:
            cout << "(5,12)\n";
            break;
        case 19:
            cout << "(5,6)\n";
            break;
        }
    }
}
