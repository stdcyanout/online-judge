#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define RED "\e[1;31m"
#define RESET "\e[0m"
#define int int64_t

using namespace std;

void debug()
{
    cerr << "\n" << RESET;
}
template<class T,class ...U> void debug(T a,U ...b)
{
    cerr << RED << a << " ", debug(b...);
}

int nxt[1000005];

signed main()
{
    fastIO
    int n,m,k,i,tmp;
    cin >> n >> m;
    iota(nxt,nxt+n,1);
    while(m--)
    {
        cin >> k;
        if(nxt[k])
        {
            cout << nxt[k] << "\n";
            tmp=nxt[k];
            nxt[k]=nxt[nxt[k]];
            nxt[tmp]=0;
        }
        else
            cout << "0u0 ...... \?\n";
    }
}