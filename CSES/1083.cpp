#include <iostream>

using namespace std;

int main()
{
    long long n,a;
    cin >> n;
    long long sum=n*(n+1)/2;
    for(int i=1;i<n;i++)
    {
        cin >> a;
        sum-=a;
    }
    cout << sum << endl;
}
