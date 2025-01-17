#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define int int64_t
#define pii pair<int,int>
#define X first
#define Y second
#define mp make_pair
#define rep(i,n) for(i=0;i<(n);++i)
#define all(x) begin(x),end(x)
using namespace std;
 
struct cmp
{
    bool operator() (const pii &p1,const pii &p2) const
    {
       return p1.Y<p2.Y;
    }
};
 
int dis(pii a,pii b)
{
    return ((a.X-b.X)*(a.X-b.X)+(a.Y-b.Y)*(a.Y-b.Y));
}
 
signed main()
{
    fastio;
    int n,i,j,l,tmp;
    cin >> n;
    vector<pii> v(n);
    multiset<pii,cmp> s;
    rep(i,n) cin >> v[i].X >> v[i].Y;
    int d=8000000000000000001;
    sort(all(v));
    for(i=0,l=0;i<n;i++)
    {
        tmp=ceil(sqrt(d));
        while(l<i&&v[i].X-v[l].X>tmp)
            s.erase(s.find(v[l++]));
        auto it_l=s.lower_bound(mp(0,v[i].Y-tmp));
        auto it_r=s.upper_bound(mp(0,v[i].Y+tmp));
        for(;it_l!=it_r;++it_l)
            d=min(d,dis(v[i],(*it_l)));
        s.insert(v[i]);
    }
    cout << d << "\n";
}