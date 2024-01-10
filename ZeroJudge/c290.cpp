#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int ans=0;
    for(int i=0;i<s.length();i++)
        if(i%2)
            ans-=s[i]-48;
        else
            ans+=s[i]-48;
    cout << abs(ans) << endl;
}
