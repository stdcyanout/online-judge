#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    getline(cin,s);
    for(int i=0;i<s.length();i++)
        cout << char(int(s[i])-7);
}
