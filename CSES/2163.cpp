#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace __gnu_pbds;
using namespace std;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int main()
{
    fastIO
    ordered_set s;
    int n,k,i,index=0;

    cin >> n >> k;

    for(i=1;i<=n;i++)
        s.insert(i);

    while(n)
    {
        index=(index+k)%n;
        n--;
        auto it=s.find_by_order(index);
        cout << *it << " ";
        s.erase(it);
    }
}
