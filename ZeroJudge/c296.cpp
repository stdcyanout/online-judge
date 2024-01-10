#include <iostream>

using namespace std;

int main()
{
    int n,m,k;
    cin >> n >> m >> k;
    int res=0;
    for(int i=n-k+1;i<=n;i++)
        res=(res+m)%i;
    cout << res+1 << endl;
}
