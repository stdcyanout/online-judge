#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define RED "\e[1;31m"
#define RESET "\e[0m"
#define int long long
#define lc 2*id
#define rc 2*id+1

using namespace std;

void debug()
{
    cerr << "\n" << RESET;
}
template<class T,class ...U> void debug(T a,U ...b)
{
    cerr << RED << a << " ", debug(b...);
}

int a[300001],dp[300001],seg[1200001];
int n;
unordered_map<int,int> ind;

void build(int L,int R,int id)
{
    if(L==R)
    {
        seg[id]=a[L];
        return;
    }
    int M=(L+R)/2;
    build(L,M,lc);
    build(M+1,R,rc);
    seg[id]=min(seg[lc],seg[rc]);
}

int query(int l,int r,int L,int R,int id)
{
    if(l<=L&&R<=r)
    {
        return seg[id];
    }
    int M=(L+R)/2;
    if(r<=M)
        return query(l,r,L,M,lc);
    else if(l>M)
        return query(l,r,M+1,R,rc);
    else
        return min(query(l,r,L,M,lc),query(l,r,M+1,R,rc));
}

int solve(int l,int r)
{
    if(l==r)
        return a[l];
    int m=ind[query(l,r,0,n-1,1)];
    if(dp[m]-dp[l]>dp[r+1]-dp[m+1])
        return solve(l,m-1);
    else
        return solve(m+1,r);
}

signed main()
{
    fastIO
    int i,l,r;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> a[i];
        dp[i+1]=dp[i]+a[i];
        ind[a[i]]=i;
    }
    build(0,n-1,1);
    cout << solve(0,n-1) << "\n";
}