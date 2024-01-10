#include <iostream>
#define MOD 1000000007

using namespace std;
long long fast_power(long long a,long long b)
{
    if(b==0)
        return 1;
    long long res=fast_power(a,b/2)%MOD;
    if(b%2==0)
        return res*res%MOD;
    return res*res%MOD*a%MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long n,a,b;
    cin >> n;
    while(n--)
    {
        cin >> a >> b;
        cout << fast_power(a,b) << "\n";
    }
}
