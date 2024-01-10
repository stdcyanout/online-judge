#include <iostream>
 
using namespace std;
 
int main()
{
    int n,i;
    long long sum=0;
    cin >> n;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for(i=1;i<n;i++)
    {
        if(a[i]<a[i-1])
        {
            sum+=a[i-1]-a[i];
            a[i]=a[i-1];
        }
    }
    cout << sum << "\n";
}