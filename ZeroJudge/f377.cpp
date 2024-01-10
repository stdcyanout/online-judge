#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define quick ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    quick

    string s,c;
    while(getline(cin,s))
    {
        stack<string> stk;
        stringstream ss;
        ss << s;
        while(ss >> c)
        {
            if(c=="(")
                stk.push(c);
            else if(c==")")
            {
                while(stk.top()!="(")
                {
                    cout << stk.top() << " ";
                    stk.pop();
                }
                stk.pop();
            }
            else if(c=="*"||c=="/")
            {
                while(!stk.empty()&&(stk.top()=="*"||stk.top()=="/"))
                {
                    cout << stk.top() << " ";
                    stk.pop();
                }
                stk.push(c);
            }
            else if(c=="+"||c=="-")
            {
                while(!stk.empty()&&(stk.top()=="*"||stk.top()=="/"||stk.top()=="+"||stk.top()=="-"))
                {
                    cout << stk.top() << " ";
                    stk.pop();
                }
                stk.push(c);
            }
            else
                cout << c << " ";
        }

        while(!stk.empty())
        {
            cout << stk.top() << " ";
            stk.pop();
        }

        cout << "\n";
    }

}
