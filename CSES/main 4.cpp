/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <bits/stdc++.h>
#define int long long
using namespace std;

int dp[200001];

signed main()
{
    int n,q,a,b,i;
    cin >> n >> q;
    for(i=1;i<=n;i++)
    {
        cin >> dp[i];
        dp[i]^=dp[i-1];
    }
    while(q--)
    {
        cin >> a >> b;
        cout << (dp[b]^dp[a-1]) << "\n";
    }
}