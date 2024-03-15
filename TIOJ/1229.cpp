//International Olympiad in Informatics Gold Medal
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define RED "\e[1;31m"
#define RESET "\e[0m"
#define int int64_t
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#undef INT_MAX
#define INT_MAX INT64_MAX
#undef INT_MIN
#define INT_MIN INT64_MIN
using namespace std;

void debug()
{
    cerr << "\n" << RESET;
}
template<class T,class ...U> void debug(T a,U ...b)
{
    cerr << RED << a << " ", debug(b...);
}

int a[101];

signed main()
{
    fastIO
    int l,n,m,i,j;
    string s,tmp;
    cin >> l >> n >> m;
    for(i=1;i<=n;i++)
        cin >> a[i];
    while(l--)
    {
        cin >> s;
        tmp=s;
        for(i=0;i<m;i++)
        {
            for(j=1;j<=n;j++)
            {  
                if(i&1)
                    s[a[j]-1]=tmp[j-1];
                else
                    tmp[a[j]-1]=s[j-1];
            }
            if(m&1)
                s=tmp;
        }
        cout << s << "\n";
    }
}