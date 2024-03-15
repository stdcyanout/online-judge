//International Olympiad in Informatics Gold Medal
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

int m,n;
bool a[512][512];
int dx[]={-1,-1,-1,0,1,1,1,0};
int dy[]={-1,0,1,1,1,0,-1,-1};
int id[]={0,1,2,3,3,4,4,5,5,5,5,6,6,7,7,8,8,9,9,10};

int fnd(int n)
{
    if(n>=20)
        return 10;
    else
        return id[n];
}

bool check(int i,int j)
{
    if(i<0 || i>=n || j<0 || j>=m || !a[i][j])
        return false;
    return true;
}

void dfs(int i,int j)
{
    a[i][j]=0;
    int k;
    for(k=0;k<8;k++)
    {
        if(check(i-dx[k],j-dy[k]))
            dfs(i-dx[k],j-dy[k]);
    }
}

signed main()
{
    fastIO
    int i,j,cnt;
    char c;
    cin >> n >> m;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin >> c;
            a[i][j]=int(c-'0');
        }
    }

    cnt=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(a[i][j])
            {
                dfs(i,j);
                ++cnt;
            }
        }
    }
    cout << fnd(cnt) << "\n";
}