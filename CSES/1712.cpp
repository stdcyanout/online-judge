#include <iostream>
#define MOD 1000000007

using namespace std;
long long fast_power(long long a,long long b,long long mod)
{
    if(b==0)
        return 1;
    long long res=fast_power(a,b/2,mod)%mod;
    if(b%2==0)
        return res*res%mod;
    return res*res%mod*a%mod;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long n,a,b,c;
    cin >> n;
    while(n--)
    {
        cin >> a >> b >> c;
        cout << fast_power(a,fast_power(b,c,MOD-1),MOD) << "\n";
    }
}
