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

int a[17][17]={};

signed main()
{
    fastIO
    int r,c,i,j;
    int det=0,all=0;
    cin >> r >> c;
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++)
        {
            cin >> a[i][j];
            if(a[i][j]==1)
            {
                ++all;
            }
        }
    }

    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++)
        {
            if(a[i][j]==5)
            {
                if(a[i-1][j-1]==5)goto c;
                if(a[i-1][j]==5)  goto c;
                if(a[i-1][j+1]==5)goto c;
                if(a[i][j-1]==5)  goto c;
                if(a[i][j+1]==5)  goto c;
                if(a[i+1][j-1]==5)goto c;
                if(a[i+1][j]==5)  goto c;
                if(a[i+1][j+1]==5)goto c;

                if(a[i-1][j-1]==1)++det,a[i-1][j-1]=0;
                if(a[i-1][j]==1)  ++det,a[i-1][j]=0;
                if(a[i-1][j+1]==1)++det,a[i-1][j+1]=0;
                if(a[i][j-1]==1)  ++det,a[i][j-1]=0;
                if(a[i][j+1]==1)  ++det,a[i][j+1]=0;
                if(a[i+1][j-1]==1)++det,a[i+1][j-1]=0;
                if(a[i+1][j]==1)  ++det,a[i+1][j]=0;
                if(a[i+1][j+1]==1)++det,a[i+1][j+1]=0;
            }
            c:;
        }
    }

    cout << det << " " << all-det << "\n";
}