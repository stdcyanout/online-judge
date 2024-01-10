#pragma GCC optimize("O3,unroll-loops")
#include <iostream>

using namespace std;

int josephu(int n,int k)
{
    if(n==1)
        return 0;
    return (josephu(n-1,k)+k)%n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,k;
    cin >> n >> k;
    for(m=2;m<=30000;m++)
    {
        if(josephu(n,m)==k-1)
        {
            cout << m << "\n";
            return 0;
        }
    }
    cout << 0 << "\n";
}
