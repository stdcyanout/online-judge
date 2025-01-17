#include <bits/stdc++.h>
#define int int64_t
using namespace std;

unordered_map<char,int> mp;

int h[500005];
bitset<600005> b;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string k, s;
    int l, i, j, pw = 1;
    cin >> k >> l >> s;
    for(i = 0; i < k.length(); i++)
        mp[k[i]] = i;
    for(i = 0; i < l; i++)
        pw *= k.length();
    for(i = 0; i < l; i++)
        h[0] = h[0] * k.length() + mp[s[i]];
    b[h[0]] = 1;
    for(i = 1; i < s.length() - l + 1; i++)
    {
        h[i] = h[i - 1] * k.length() - mp[s[i - 1]] * pw + mp[s[i + l - 1]];
        b[h[i]] = 1;
    }
    for(j = 0; j <= 600000; j++)
        if(!b[j])
            break;
    vector<int> ans;
    for(i = 0; i < l; i++)
    {
        ans.emplace_back(j % k.length());
        j /= k.length();
    }
    for(i = l - 1; i >= 0; i--)
        cout << k[ans[i]];
    cout << "\n";
}