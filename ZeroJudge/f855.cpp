#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define RED "\e[1;31m"
#define RESET "\e[0m" 
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair

using namespace std;

void debug()
{
    cerr << "\n" << RESET;
}
template<class T,class ...U> void debug(T a,U ...b)
{
    cerr << RED << a << " ", debug(b...);
}

int main()
{
    fastIO
    vector<pii> spawline;
    int n,l,r;
    cin >> n;
    while(n--)
    {
        cin >> l >> r;
        spawline.push_back(mp(l,r));
    }
    spawline.push_back(mp(1e7+1,1e7+1));
    
    sort(spawline.begin(),spawline.end());
    int len=0;
    l=r=0;
    for(pii p:spawline)
    {
        if(p.F<=r)
            r=max(r,p.S);
        else
        {
            len+=r-l;
            l=p.F;
            r=p.S;
        }
    }
    
    cout << len << "\n";
}