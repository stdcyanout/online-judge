/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <bits/stdc++.h>
#define int long long
#define lc 2*id+1
#define rc 2*id+2
using namespace std;

int a[200001],seg[400001];

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
        return seg[id];
    int M=(L+R)/2;
    if(r<=M)
        return query(l,r,L,M,lc);
    if(l>=M+1)
        return query(l,r,M+1,R,rc);
    return min(query(l,r,L,M,lc),query(l,r,M+1,R,rc));
}

void update(int k,int u,int L,int R,int id)
{
    if(L==R)
    {
        seg[id]=u;
        return;
    }
    int M=(L+R)/2;
    if(k<=M)
        update(k,u,L,M,lc);
    else
        update(k,u,M+1,R,rc);
    seg[id]=min(seg[lc],seg[rc]);
}

signed main()
{
    int n,q,i,s,t,u;
    cin >> n >> q;
    for(i=0;i<n;i++)
        cin >> a[i];
    build(0,n-1,0);
    while(q--)
    {
        cin >> s >> t >> u;
        if(s==1)
            update(t-1,u,0,n-1,0);
        if(s==2)
            cout << query(t-1,u-1,0,n-1,0) << "\n";
    }
}