#include <bits/stdc++.h>
#define int long long
using namespace std;
string input()
{
    string s,tmp="";
    cin >> s;
    reverse(s.begin(),s.end());
    for(int i=0;i<s.length();i++)
    {
        if('0'<=s[i]&&s[i]<='9')
        {
            tmp+=s[i];
            if(tmp.length()==4)
                break;
        }
    }
    return tmp;
}
signed main()
{
    int n,ans=0;
    cin >> n;
    while(n--)
    {
        string s=input();
        if(s[0]==s[1]&&s[1]==s[2]&&s[2]==s[3])
            ans+=2000;
        else if((s[0]==s[1]&&s[1]==s[2])||(s[1]==s[2]&&s[2]==s[3]))
            ans+=1000;
        else if(s[0]==s[1]&&s[2]==s[3])
            ans+=1500;
    }
    cout << ans << "\n";
}