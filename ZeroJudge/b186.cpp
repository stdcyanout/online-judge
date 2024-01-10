#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a,b,c,aprime,cprime;
    while(cin >> a >> b >> c)
    {
        aprime=a;
        cprime=c;
        while(aprime>=10&&cprime>=2)
        {
            b++;
            aprime-=10;
            cprime-=2;
        }
        cout << a << " 個餅乾，" << b << " 盒巧克力，" << c << " 個蛋糕。\n";
    }

}
