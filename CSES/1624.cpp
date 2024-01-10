#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define quick ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

bool f[8][8];
int queen[8];
int cnt;

bool check(int x,int y)
{
    int i;
    if(f[x][y])
    {
        for(i=0;i<x;i++)
        {
            if(y==queen[i])
                return 0;
            if(abs(x-i)==abs(queen[i]-y))
                return 0;
        }
        return 1;
    }
    else
        return 0;
}

void eight_queen(int x)
{
    if(x==8)
    {
        cnt+=1;
        return;
    }
    int i;
    for(i=0;i<8;i++)
    {
        if(check(x,i))
        {
            queen[x]=i;
            eight_queen(x+1);
        }
    }
}

int main()
{
    quick
    int i,j;
    char c;
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            cin >> c;
            if(c=='.')
                f[i][j]=1;
        }
    }
    eight_queen(0);
    cout << cnt << "\n";
}
