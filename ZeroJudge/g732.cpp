#include <iostream>

using namespace std;

int a[501];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,i,x;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> x;
        a[x]+=1;
    }
    n=(n+1)/2;
    for(i=1;i<=500;i++)
    {
        n-=a[i];
        if(n<=0)
        {
            cout << i << endl;
            break;
        }
    }
}
