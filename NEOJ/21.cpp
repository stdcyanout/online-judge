#include <bits/stdc++.h>
using namespace std;
int prv[100005], nxt[100005];
vector<int> ans;
int main() {
    int n, m, t, x, tmp, first = 1, i;
    cin >> n >> m;
    iota(prv, prv + n + 1, -1);
    iota(nxt, nxt + n + 1, 1);
    while (m--) {
        cin >> t >> x;
        if (t == 0) {
            if (x == first)
                first = nxt[first];
            else {
                prv[nxt[x]] = prv[x];
                nxt[prv[x]] = nxt[x];
            }
        } else if (x != first) {
            if (prv[x] == first) {
                first = x;
                tmp = prv[x];
                nxt[tmp] = nxt[x];
                prv[x] = prv[tmp];
                prv[nxt[x]] = tmp;
                prv[tmp] = x;
                nxt[x] = tmp;
            } else {
                tmp = prv[x];
                nxt[tmp] = nxt[x];
                prv[x] = prv[tmp];
                nxt[prv[tmp]] = x;
                prv[nxt[x]] = tmp;
                prv[tmp] = x;
                nxt[x] = tmp;
            }
        }
    }
    int cur = first;
    while (cur <= n) {
        ans.emplace_back(cur);
        cur = nxt[cur];
    }
    for (i = 0; i < ans.size(); i++) {
        cout << ans[i] << " \n"[i == ans.size() - 1];
    }
}