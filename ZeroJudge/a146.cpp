#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

int main()
{
    fastIO
    int n,k,i;
    while(cin >> n >> k)
    {
        if(k>n)
            k=n;

        vector<int> v(n);

        for(i=0;i<n;i++)
            cin >> v[i];

        deque<int> monoqueue;
        for(i=0;i<n;i++)
        {
            while(!monoqueue.empty()&&monoqueue.front()<i-k+1)
                monoqueue.pop_front();

            while(!monoqueue.empty()&&v[monoqueue.back()]>v[i])
                monoqueue.pop_back();

            monoqueue.push_back(i);

            if(i>=k-1)
            {
                if(i==n-1)
                    cout << v[monoqueue.front()];
                else
                    cout << v[monoqueue.front()] << " ";
            }
        }
        cout << "\n";

        monoqueue.clear();
        for(i=0;i<n;i++)
        {
            while(!monoqueue.empty()&&monoqueue.front()<i-k+1)
                monoqueue.pop_front();

            while(!monoqueue.empty()&&v[monoqueue.back()]<v[i])
                monoqueue.pop_back();

            monoqueue.push_back(i);

            if(i>=k-1)
            {
                if(i==n-1)
                    cout << v[monoqueue.front()];
                else
                    cout << v[monoqueue.front()] << " ";
            }
        }
        cout << "\n";
    }
}
