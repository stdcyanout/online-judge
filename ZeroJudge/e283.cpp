#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,i;
    int s[4];
    while(cin >> n)
    {
        for(i=0;i<n;i++)
        {
            cin >> s[0] >> s[1] >> s[2] >> s[3];
            if(s[0]==1)
            {
                if(s[1]==1)
                {
                    if(s[3]==1)
                        cout << "D";
                    else
                        cout << "F";
                }
                else
                {
                    cout << "E";
                }
            }
            else
            {
                if(s[1]==1)
                {
                    if(s[2]==1)
                        cout << "B";
                    else
                        cout << "A";
                }
                else
                {
                    cout << "C";
                }
            }
        }
        cout << "\n";
    }
}
