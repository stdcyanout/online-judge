#include <bits/stdc++.h>
using namespace std;

int ans=0;
int solve(int n)
{
    ans+=n;
    return n && solve(n-1);
}

int main()
{
    int n;
    scanf("%d",&n);
    solve(n);
    printf("%d\n",ans);
}
