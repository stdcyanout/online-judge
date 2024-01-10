#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define RED "\e[1;31m"
#define RESET "\e[0m"
#define int long long

using namespace std;

//𝑓(𝑥) = 2𝑥 – 3
//𝑔(𝑥, 𝑦) = 2𝑥 + 𝑦 – 7
//ℎ(𝑥, 𝑦, 𝑧) = 3𝑥 – 2𝑦 + 𝑧

void debug()
{
    cerr << "\n" << RESET;
}
template<class T,class ...U> void debug(T a,U ...b)
{
    cerr << RED << a << " ", debug(b...);
}

int f(int x)
{
    return 2*x-3;
}

int g(int y,int x)
{
    return 2*x+y-7;
}

int h(int z,int y,int x)
{
    return 3*x-2*y+z;
}

int input()
{
    string s;
    cin >> s;
    if(s=="f")
    {
        return f(input());
    }

    else if(s=="g")
    {
        return g(input(),input());
    }

    else if(s=="h")
    {
        return h(input(),input(),input());
    }

    else
    {
        return stoi(s);
    }
}

signed main()
{
    fastIO
    cout << input() << "\n";
}