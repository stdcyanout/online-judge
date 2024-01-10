#include <bits/stdc++.h>
 
using namespace std;
 
void hanoi(int a,int b,int c)
{
    if(a>1)
        hanoi(a-1,b,6-b-c);
    cout << b << " " << c << "\n";
    if(a>1)
        hanoi(a-1,6-b-c,c);
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int a;
    cin >> a;
    cout << pow(2,a)-1 << "\n";
    hanoi(a,1,3);
}