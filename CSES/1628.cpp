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

int t[40],a[20],b[20],sa[1<<20],sb[1<<20],tmp[1<<20];

signed main()
{
    int n,x,i,j,sza,szb,ptr,ans=0;
    cin >> n >> x;
    rep(i,n) cin >> t[i];
    int na=n/2,nb=n-n/2;
    rep(i,na) a[i]=t[i];
    rep(i,nb) b[i]=t[i+na];
    sza=1;
    rep(i,na)
    {
        ptr=sza;
        rep(j,ptr)
        {
            if(a[i]+sa[j]>x)
                break;
            sa[sza++]=a[i]+sa[j];
        }
        merge(sa,sa+ptr,sa+ptr,sa+sza,tmp);
        copy(tmp,tmp+sza,sa);
    }
    szb=1;
    rep(i,nb)
    {
        ptr=szb;
        rep(j,ptr)
        {
            if(b[i]+sb[j]>x)
                break;
            sb[szb++]=b[i]+sb[j];
        }
        merge(sb,sb+ptr,sb+ptr,sb+szb,tmp);
        copy(tmp,tmp+szb,sb);
    }
    rep(i,sza)
    {
        ans+=upper_bound(sb,sb+szb,x-sa[i])-lower_bound(sb,sb+szb,x-sa[i]);
    }
    cout << ans << "\n";
}