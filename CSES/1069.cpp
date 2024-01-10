#include <iostream>
 
using namespace std;
 
int main()
{
    int t=0,Max=0;
    char a='B',b;
    while(cin >> b)
    {
        if(a==b)
        {
            t++;
            Max=max(Max,t);
        }
        else
        {
            t=0;
        }
        a=b;
    }
    cout << Max+1 << endl;
}
