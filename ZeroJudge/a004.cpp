#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while(cin >> n)
    {
        if((n%400==0)||(n%100!=0&&n%4==0))
            cout << "閏年\n";
        else
            cout << "平年\n";
    }
}
