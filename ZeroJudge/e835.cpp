#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if(n<=2500)
        cout << "1 " << ((n-1)/25)+1 << " " << ((n-1)%25)+1 << endl;
    if(2500<n&&n<=7500)
        cout << "2 " << ((n-2501)/50)+1 << " " << ((n-2501)%50)+1 << endl;
    if(7500<n)
        cout << "3 " << ((n-7501)/25)+1 << " " << ((n-7501)%25)+1 << endl;
}
