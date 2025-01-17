#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int h,w;
int a[25][25];

void solve(int r,int c,int t,int x)
{
    int i,j;
    for(i = 0; i < h; i++)
    {
        for(j = 0; j < w; j++)
        {
            if(abs(r - i) + abs(c - j) <= t)
                a[i][j] += x;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,r,c,t,x,i,j;
    cin >> h >> w >> n;
    while(n--)
    {
        cin >> r >> c >> t >> x;
        solve(r,c,t,x);
    }
    for(i=0;i<h;i++)
    {
        for(j=0;j<w;j++)
            cout << a[i][j] << " \n"[j==w-1];
    }
}