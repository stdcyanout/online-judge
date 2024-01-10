#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    fastIO
    int n,i,a=1,b=0;
    cin >> n;
    while(n)
    {
    	for(i=2;i<=n;i+=2)
        {
    		cout << a*i+b << " ";
    	}
    	if(n&1)
    	{
            cout << a+b << " ";
            b+=a;
    	}
    	else
            b-=a;
    	a<<=1;
    	n>>=1;
    }
}
