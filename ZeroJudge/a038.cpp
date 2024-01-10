#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int i;
    for(i=0;i<s.length();i++)
    {
        if(s[i]!='0')
            break;
    }
    if(i==s.length())
    {
        cout << "0" << endl;
        return 0;
    }
    reverse(s.begin()+i,s.end());
    for(;i<s.length();i++)
    {
        if(s[i]!='0')
            break;
    }
    for(;i<s.length();i++)
        cout << s[i];
    cout << endl;
}
