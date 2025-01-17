#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define RED "\e[1;31m"
#define RESET "\e[0m"
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define rep(i,n) for(i=0;i<(n);++i)
#define foo(i,a,b) for(i=(a);i<=(b);++i)
#define oof(i,a,b) for(i=(a);i>=(b);--i)
#define all(x) begin(x),end(x)
#define btw(a,b,c) ((a)<=(b)&&(b)<=(c))
#define setpr(x) cout << fixed << setprecesion(x)
#define indexed_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
typedef long long INT;
typedef long double DOUBLE;
#define int INT
#define double DOUBLE
#define pii pair<int,int>
#define eps (1e-6)
#define pi (acos(-1))
#undef INT_MAX
#define INT_MAX LONG_LONG_MAX
#undef INT_MIN
#define INT_MIN LONG_LONG_MIN

template<class T> void debug(T a)
{
    cerr << a << "\n" << RESET;
}
template<class T,class ...U> void debug(T a,U ...b)
{
    cerr << RED << a << " ", debug(b...);
}

#define max MAX
template<class T> T MAX(T a,T b)
{
    return a>b?a:b;
}
template<class T,class ...U> T MAX(T a,U ...b)
{
    T tmp=MAX(b...);
    return a>tmp?a:tmp;
}

#define min MIN
template<class T> T MIN(T a,T b)
{
    return a<b?a:b;
}
template<class T,class ...U> T MIN(T a,U ...b)
{
    T tmp=MAX(b...);
    return a<tmp?a:tmp;
}

int alpha[26];

bool cmp(char a,char b)
{
    return alpha[int(a-'A')]<alpha[int(b-'A')];
}

signed main()
{
    fastIO
    string a,b;
    int i,x;
    cin >> a >> b;
    rep(i,a.length())
    {
        alpha[int(a[i]-'A')]=i;
    }
    sort(all(b),cmp);
    cin >> i;
    while(i--)
    {
        cin >> x;
        cout << b[x-1] << "\n";
    }
}