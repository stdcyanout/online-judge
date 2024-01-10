#include <iostream>
#define MOD 1000000007

using namespace std;

long long fact[1000001],inv_fact[1000001];

long long fast_power(long long a,long long n)
{
    if(n==0)
        return 1;
    long long res=fast_power(a,n>>1)%MOD;
    if(n&1)
        return res*res%MOD*a%MOD;
    return res*res%MOD;
}

int main()
{
    long long i,n,k;

    fact[0]=fact[1]=1;
    inv_fact[0]=inv_fact[1]=1;
    for(i=2;i<=1000000;i++)
    {
        fact[i]=fact[i-1]*i%MOD;
        inv_fact[i]=fast_power(fact[i],MOD-2);
    }

    cin >> i;
    while(i--)
    {
        cin >> n >> k;
        cout << fact[n]*inv_fact[k]%MOD*inv_fact[n-k]%MOD << "\n";
    }
}
