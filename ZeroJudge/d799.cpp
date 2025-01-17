#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fastio ios_base::sync_with_stdio(false),cin.tie(0);
#define safe cerr << "\e[1;31m" << __PRETTY_FUNCTION__ << " line " << __LINE__ << " safe\e[0m\n";
#define int int64_t
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define rep(i,n) for(i=0;i<(n);++i)
#define foo(i,a,b) for(i=(a);i<=(b);++i)
#define oof(i,a,b) for(i=(a);i>=(b);--i)
#define all(x) begin(x),end(x)
#define btw(a,b,c) ((a)<=(b)&&(b)<=(c))
#define lowbit(x) ((x)&-(x))
#define lc 2*id+1
#define rc 2*id+2
using namespace __gnu_pbds;
using namespace std;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

template <class ...T> void debug(T ...args)
{
    int cnt = sizeof...(T);
    ((cerr << "\e[1;31m"), ..., (cerr << args << (--cnt ? " " : "\e[0m\n")));
}
template <class T> void orange(T L, T R)
{
    cerr << "\e[1;31m";
    for (int f = 0; L != R; ++L) cerr << (f++ ? " " : "") << *L;
    cerr << "\e[0m\n";
}

int a[500001];
struct node
{
    int sum;
    int tag;
} seg[2000005];

void pull(int id)
{
    seg[id].sum=seg[lc].sum+seg[rc].sum;
}

void push(int L,int R,int id)
{
    int M=(L+R)/2;
    seg[lc].sum+=(M-L)*seg[id].tag;
    seg[rc].sum+=(R-M)*seg[id].tag;
    seg[lc].tag+=seg[id].tag;
    seg[rc].tag+=seg[id].tag;
    seg[id].tag=0;
}

void build(int L,int R,int id)
{
    if(L==R-1)
    {
        seg[id].sum=a[L];
        return;
    }
    int M=(L+R)/2;
    build(L,M,lc);
    build(M,R,rc);
    pull(id);
}

void update(int L,int R,int id,int l,int r,int val)
{
    if(R<=l||r<=L)
        return;
    if(l<=L&&R<=r)
    {
        seg[id].sum+=(R-L)*val;
        seg[id].tag+=val;
        return;
    }
    int M=(L+R)/2;
    push(L,R,id);
    update(L,M,lc,l,r,val);
    update(M,R,rc,l,r,val);
    pull(id);
}

int query(int L,int R,int id,int l,int r)
{
    if(R<=l||r<=L)
        return 0;
    if(l<=L&&R<=r)
        return seg[id].sum;
    int M=(L+R)/2;
    push(L,R,id);
    return query(L,M,lc,l,r)+query(M,R,rc,l,r);
}

signed main()
{
    fastio;
    int n,q,i,v,x,y,k;
    cin >> n;
    rep(i,n) cin >> a[i];
    build(0,n,0);
    cin >> q;
    while(q--)
    {
        cin >> v;
        if(v==1)
        {
            cin >> x >> y >> k;
            update(0,n,0,x-1,y,k);
        }
        else
        {
            cin >> x >> y;
            cout << query(0,n,0,x-1,y) << "\n";
        }
    }
}

/*
int n,a[500001],bit[2][500001];

void build()
{
    int i,p;
    foo(i,1,n)
    {
        bit[0][i]+=a[i]-a[i-1];
        bit[1][i]+=i*(a[i]-a[i-1]);
        p=i+lowbit(i);
        if(p<=n)
        {
            bit[0][p]+=bit[0][i];
            bit[1][p]+=bit[1][i];
        }
    }
}

void update(int x,int y,int k)
{
    int i;
    for(i=x;i<=n;i+=lowbit(i))
    {
        bit[0][i]+=k;
        bit[1][i]+=x*k;
    }
    for(i=y+1;i<=n;i+=lowbit(i))
    {
        bit[0][i]-=k;
        bit[1][i]-=(y+1)*k;
    }
}

int query(int x,int y)
{
    int ans=0,i;
    for(i=y;i>0;i-=lowbit(i))
        ans+=(y+1)*bit[0][i]-bit[1][i];
    for(i=x-1;i>0;i-=lowbit(i))
        ans-=x*bit[0][i]-bit[1][i];
    return ans;
}

signed main()
{
    fastio;
    int q,i,v,x,y,k;
    cin >> n;
    foo(i,1,n) cin >> a[i];
    build();
    cin >> q;
    while(q--)
    {
        cin >> v;
        if(v==1)
        {
            cin >> x >> y >> k;
            update(x,y,k);
        }
        if(v==2)
        {
            cin >> x >> y;
            cout << query(x,y) << "\n";
        }
    }
}*/