#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false),cin.tie(0);
#define int int64_t
#define pii pair<int, int>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define rep(i, n) for(i = 0; i < (n); ++i)
#define foo(i, a, b) for(i = (a); i <= (b); ++i)
#define oof(i, a, b) for(i = (a); i >= (b); --i)
#define all(x) x.begin(), x.end()
using namespace std;

const int INF = 0x3F3F3F3F3F3F3F3F;
int a[2000001];
stack<int> s;

signed main()
{
    int n, i, sum = 0;
    cin >> n;
    a[0] = INF;
    s.push(0);
    foo(i, 1, n)
        cin >> a[i];
    foo(i, 1, n)
    {
        while(a[s.top()] <= a[i])
            s.pop();
        sum += i - s.top();
        s.push(i);
    }
    cout << sum << "\n";
}