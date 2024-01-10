#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    int t,a,x,y,z,w,n,m,disgust;
    cin >> t;
    while(t--)
    {
        cin >> x >> y >> z >> w >> n >> m;
        getline(cin,s);
        getline(cin,s);
        stringstream stream;
        stream << s;
        disgust=0;
        while(stream >> a)
        {
            m-=disgust*n;
            if(a==3)
                m-=z;
            if(a==4)
            {
                m-=w;
                disgust++;
            }
            if(m<0)
            {
                break;
            }
            if(a==1)
                m+=x;
            if(a==2)
                m+=y;
        }
        if(m<0)
            cout << "bye~Rabbit" << "\n";
        else
            cout << m << "g" << "\n";

    }
    return 0;
}
