#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    while(cin >> n >> k)
    {
        if(n==0)
            cout << "Ok!" << "\n";
        else if(k!=0)
        {
            if(n%k==0)
                cout << "Ok!" << "\n";
            else
                cout << "Impossib1e!" << "\n";
        }
        else
            cout << "Impossib1e!" << "\n";
    }
}
