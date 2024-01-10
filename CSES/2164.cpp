#include <bits/stdc++.h>

using namespace std;

int josh(int n,int k)
{
    if(n==1||k*2==n+1)
        return 1;
    if(k<=(n+1)/2)
        return k*2;
    int c=josh(n>>1,k-(n+1)/2);
    if(n&1)
        return c*2+1;
    return c*2-1;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int q,n,k;
    cin >> q;
    while(q--)
    {
        cin >> n >> k;
        cout << josh(n,k) << "\n";
    }
}
