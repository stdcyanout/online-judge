#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m,ans=1,i;
    string s;
    cin >> n;
    getline(cin,s);
    while(n--)
    {
        getline(cin,s);
        ans=1;
        for(i=0;i<s.length();i++)
        {
            m=0;
            if(s[i]=='-')
            {
                ans*=-1;
                i++;
            }
            while(int(s[i])>=48&&int(s[i])<=57)
            {
                m=m*10+int(s[i])-48;
                i++;
            }
            ans*=m;
        }
        cout << ans << "\n";
    }
}
