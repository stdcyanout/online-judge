#include <iostream>

using namespace std;

int a[31];

int hanoi(int n,int s)
{
    if(s%2)
        return 1;
    if(s==a[n-1])
        return n;
    if(s<a[n-1])
        return hanoi(n-1,s);
    return hanoi(n-1,a[n]-s);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    a[0]=1;
    int t,n,s;
    for(t=1;t<31;t++)
        a[t]=a[t-1]*2;

    cin >> t;
    while(t--)
    {
        cin >> n >> s;
        cout << hanoi(n,s) << "\n";
    }
}
