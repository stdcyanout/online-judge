#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    multiset<int> s;
    int c;
    for(int i=0;i<n;i++)
    {
        cin >> c;
        s.insert(c);
    }

    for(auto it=s.begin();it!=s.end();it++)
        cout << *it << " ";
    cout << "\n";

    auto up=lower_bound(s.begin(),s.end(),60);
    if(up!=s.begin())
    {
        cout << *--up << "\n";
        up++;
    }
    else
        cout << "best case\n";

    if(up!=s.end())
        cout << *up << "\n";
    else
        cout << "worst case\n";
}
