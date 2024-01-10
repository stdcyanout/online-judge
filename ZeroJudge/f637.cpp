#include <bits/stdc++.h>

using namespace std;

int n;

int df(string s,int d)
{
    if(s=="0")
        return 0;
    if(s=="1")
        return pow((n/pow(2,d)),2);
    string subs;
    int len,res=0;
    for(int i=1;i<s.length();)
    {
        subs="";
        len=1;
        while(len)
        {
            subs+=s[i];
            if(s[i]=='2')
                len+=4;
            len--;
            i++;
        }
        res+=df(subs,d+1);
    }
    return res;
}

int main()
{
    string s;
    cin >> s >> n;
    cout << df(s,0) << endl;
}
