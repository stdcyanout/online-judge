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
#define INF 0x3f3f3f3f3f3f3f3f
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

/* sparse table */
/*
int s[20][200001];

signed main()
{
    fastio;
    int n,q,i,j,a,b,k;
    cin >> n >> q;
    rep(i,n) cin >> s[0][i];
    k=__lg(n);
    foo(i,1,k)
    {
        rep(j,n-(1<<i)+1)
        {
            s[i][j]=min(s[i-1][j],s[i-1][j+(1<<(i-1))]);
        }
    }
    while(q--)
    {
        cin >> a >> b;
        k=__lg(b-a+1);
        cout << min(s[k][a-1],s[k][b-(1<<k)]) << "\n";
    }
}*/

/* fenwick tree */

int n,arr[200001],bit[200001];

void build()
{
    memset(bit,0x3f,sizeof(bit));
    int i,p;
    foo(i,1,n)
    {
        bit[i]=min(bit[i],arr[i]);
        p=i+lowbit(i);
        if(p<=n) bit[p]=min(bit[p],bit[i]);
    }
}

int query(int a,int b)
{
    if(a>b)
        return INF;
    if(b-lowbit(b)+1>=a)
        return min(bit[b],query(a,b-lowbit(b)));
    return min(arr[b],query(a,b-1));
}

signed main()
{
    fastio;
    int q,a,b,i;
    cin >> n >> q;
    foo(i,1,n) cin >> arr[i];
    build();
    while(q--)
    {
        cin >> a >> b;
        cout << query(a,b) << "\n";
    }
}