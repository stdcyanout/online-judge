#include <iostream>
#define MOD 1000000007
 
using namespace std;
 
int fast_power(int a)
{
    if(a==0)
        return 1;
    long long res = fast_power(a>>1);
    if(a&1)
        return res*res%MOD*2%MOD;
    else
        return res*res%MOD;
}
 
int main()
{
    int n;
    cin >> n;
    cout << fast_power(n) << endl;
}