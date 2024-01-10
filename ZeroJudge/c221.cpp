#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define RED "\e[1;31m"
#define RESET "\e[0m"

using namespace std;

void debug()
{
    cerr << "\n" << RESET;
}
template<class T,class ...U> void debug(T a,U ...b)
{
    cerr << RED << a << " ", debug(b...);
}

int main()
{
    fastIO
    cout << 2147483645 << " " << 2147483646 << "\n";
}