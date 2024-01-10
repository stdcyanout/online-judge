#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define quick ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

vector<string> gray_code(int n)
{
    if(n==1)
    {
        vector<string> v={"0","1"};
        return v;
    }
    int i;
    vector<string> v,vprime;
    v=gray_code(n-1);
    vprime=v;
    reverse(vprime.begin(),vprime.end());
    for(i=0;i<v.size();i++)
    {
        v[i]+="0";
    }
    for(i=0;i<vprime.size();i++)
    {
        vprime[i]+="1";
    }
    v.insert(v.end(),vprime.begin(),vprime.end());
    return v;
}

int main()
{
    quick
    int n;
    cin >> n;
    vector<string> ans=gray_code(n);
    for(string s:ans)
    {
        cout << s << "\n";
    }
}
