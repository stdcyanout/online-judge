#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define RED "\e[1;31m"
#define RESET "\e[0m"
#define int long long

using namespace std;

void debug()
{
    cerr << "\n" << RESET;
}
template<class T,class ...U> void debug(T a,U ...b)
{
    cerr << RED << a << " ", debug(b...);
}

signed main()
{
    fastIO
    int i,j,n,m,d;
    cin >> n >> m;
    int score[n][m],solve[n][2]={}; //solve[n][0]進步 solve[n][1]退步
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin >> score[i][j];
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=1;j<m;j++)
        {
            d=score[i][j]-score[i][j-1];
            solve[i][d<0]+=d;
        }
    }

    int a=0,b=0;
    for(i=0;i<n;i++)
    {
        if(solve[i][0]>solve[a][0])
            a=i;
        if(solve[i][1]<solve[b][1])
            b=i;
    }
    cout << a+1 << "\n" << b+1 << "\n";
}