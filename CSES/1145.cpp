#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

const int MAXN = 200005; // 輸入序列的最大長度
int n; // 輸入序列的長度
vector<int> inputSequence(MAXN); // 輸入序列
vector<int> tree(4 * MAXN, 0); // 線段樹，初始值為0

// 更新線段樹中的節點
void update(int node, int start, int end, int index, int value) {
    if (start == end) {
        // 葉節點，更新數值
        tree[node] = value;
    } else {
        int mid = (start + end) / 2;
        if (index <= mid) {
            // 要更新的節點在左子樹
            update(2 * node, start, mid, index, value);
        } else {
            // 要更新的節點在右子樹
            update(2 * node + 1, mid + 1, end, index, value);
        }
        // 更新父節點
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }
}

// 查詢線段樹中某一範圍的最大值
int query(int node, int start, int end, int left, int right) {
    if (start > right || end < left) {
        // 範圍不重疊，返回一個極小值
        return 0;
    }
    if (left <= start && end <= right) {
        // 範圍完全包含在查詢範圍內，返回該範圍的最大值
        return tree[node];
    }
    int mid = (start + end) / 2;
    // 分別查詢左子樹和右子樹
    int leftMax = query(2 * node, start, mid, left, right);
    int rightMax = query(2 * node + 1, mid + 1, end, left, right);
    // 返回左子樹和右子樹的最大值
    return max(leftMax, rightMax);
}

// 計算最長遞增子序列（LIS）
int findLIS() {
    vector<int> lis(n, 0); // 存儲每個位置的LIS長度
    for (int i = 0; i < n; i++) {
        // 查詢[0, inputSequence[i] - 1]範圍內的最大值
        int maxLIS = query(1, 0, MAXN - 1, 0, inputSequence[i] - 1);
        // 更新LIS值
        lis[i] = maxLIS + 1;
        // 更新線段樹
        update(1, 0, MAXN - 1, inputSequence[i], lis[i]);
    }
    // 找到LIS中的最大值
    return *max_element(lis.begin(), lis.end());
}

int main() {
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> inputSequence[i];

    int result = findLIS();
    cout << result << "\n";

    return 0;
}
