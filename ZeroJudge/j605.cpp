#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int t,s,maxs=-1,maxst,rs=-n;
    for(int i=0;i<n;i++)
    {
        cin >> t >> s;
        if(s>maxs)
        {
            maxs=s;
            maxst=t;
        }
        if(s==-1)
            rs-=2;
    }
    rs+=maxs;
    if(rs<0)
        rs=0;
    cout << rs << " " << maxst << endl;
}
