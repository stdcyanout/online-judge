#include <iostream>
#define MOD 1000000007

using namespace std;

long long fast_power(long long n)
{
    if(n==0)
        return 1;
    long long res=fast_power(n>>1)%MOD;
    if(n&1)
        return res*res%MOD*2%MOD;
    return res*res%MOD;
}

int main()
{
    long long n;
    cin >> n;
    if(n>=2)
        cout << n*(n-1)%MOD*fast_power(n-2)%MOD << "\n";
    else
        cout << 0 << "\n";
}
