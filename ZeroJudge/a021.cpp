#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fastio ios_base::sync_with_stdio(false),cin.tie(0);
#define safe cerr << "\e[1;31m" << __PRETTY_FUNCTION__ << " line " << __LINE__ << " safe\e[0m\n";
#define int int64_t
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define rep(i,n) for(i=0;i<(n);++i)
#define foo(i,a,b) for(i=(a);i<=(b);++i)
#define oof(i,a,b) for(i=(a);i>=(b);--i)
#define all(x) begin(x),end(x)
#define btw(a,b,c) ((a)<=(b)&&(b)<=(c))
using namespace __gnu_pbds;
using namespace std;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

template <class ...T> void debug(T ...args)
{
    int cnt = sizeof...(T);
    ((cerr << "\e[1;31m"), ..., (cerr << args << (--cnt ? " " : "\e[0m\n")));
}
template <class T> void orange(T L, T R)
{
    cerr << "\e[1;31m";
    for (int f = 0; L != R; ++L) cerr << (f++ ? " " : "") << *L;
    cerr << "\e[0m\n";
}

int tmp[505];

bool cmp(string a, string b)
{
    if(a.length() == b.length())
        return a < b;
    return a.length() < b.length();
}

string add(string a, string b)
{
    if(cmp(a, b))
        swap(a, b);
    int n = a.length(), m = b.length(), d;
    for(int i = 0; i < n + 1; i++)
        tmp[i] = 0;
    for(int i = 0; i < n; i++)
    {
        if(m - i - 1 >= 0)
            tmp[i] += int(a[n - i - 1] - '0') + int(b[m - i - 1] - '0');
        else
            tmp[i] += int(a[n - i - 1] - '0');
        if(tmp[i] > 9)
        {
            d = i + 1;
            tmp[i + 1] += 1;
            tmp[i] -= 10;
        }
        else
            d = i;

    }
    string res = "";
    for(int i = d; i >= 0; i--)
        res += char(tmp[i] + '0');
    return res;
}

string sub(string a, string b)
{
    if(cmp(a, b))
    {
        string res = sub(b, a);
        res = "-" + res;
        return res;
    }
    int n = a.length(), m = b.length(), d = 0;
    for(int i = 0; i < n; i++)
        tmp[i] = 0;
    for(int i = 0; i < n; i++)
    {
        if(m - i - 1 >= 0)
            tmp[i] += int(a[n - i - 1] - '0') - int(b[m - i - 1] - '0');
        else
            tmp[i] += int(a[n - i - 1] - '0');
        if(tmp[i] < 0)
        {
            tmp[i + 1] -= 1;
            tmp[i] += 10;
        }
        if(tmp[i] != 0)
            d = i;
    }
    string res = "";
    for(int i = d; i >= 0; i--)
        res += char(tmp[i] + '0');
    return res;
}

string mult(string a, string b)
{
    string res = "";
    int m = b.length();
    for(int i = m - 1; i >= 0; i--)
    {
        int t = int(b[i] - '0');
        while(t--)
            res = add(res, a);
        a += "0";
    }
    return res;
}

string div(string a, string b)
{
    if(cmp(a, b)) return "0";
    string res = "";
    int cnt = 1;
    while(!cmp(a, b + "0"))
    {
        b += "0";
        cnt++;
    }
    while(cnt--)
    {
        int t = 0;
        while(!cmp(a, b))
        {
            a = sub(a, b);
            t++;
        }
        res += char(t + '0');
        if(cnt) b.pop_back();
    }
    return res;
}

signed main()
{
    fastio;
    string a, op, b;
    cin >> a >> op >> b;
    if(op == "+")
        cout << add(a, b) << "\n";
    else if(op == "-")
        cout << sub(a, b) << "\n";
    else if(op == "*")
        cout << mult(a, b) << "\n";
    else
        cout << div(a, b) << "\n";
}