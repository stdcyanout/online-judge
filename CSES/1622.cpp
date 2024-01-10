#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define quick ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

queue<string> q;
set<string> sset;
string s;

inline string getstring(char c)
{
    string s(1,c);
    return s;
}

void check(int x)
{
    if(x==s.length())
        return;
    int t=q.size();
    string subs,subsprime;
    while(t--)
    {
        subs=q.front();
        q.pop();
        for(int i=0;i<=x;i++)
        {
            subsprime=subs;
            subsprime.insert(i,getstring(s[x]));
            if(x==s.length()-1)
                sset.insert(subsprime);
            else
                q.push(subsprime);
        }
    }
    check(x+1);
}

int main()
{
    quick
    q.push("");
    cin >> s;
    check(0);

    cout << sset.size() << "\n";
    for(string i:sset)
        cout << i << "\n";
}
