#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n, budget;
    vector<int> present, future;
    vector<vector<int>> tree;

    // dp cache: dp[u] = {noDiscountDP, withDiscountDP}
    vector<pair<vector<int>, vector<int>>> memo;
    vector<bool> visited;

    vector<int> mergeDP(const vector<int>& A, const vector<int>& B) {
        int BUD = A.size();
        vector<int> merged(BUD, INT_MIN);

        for (int i = 0; i < BUD; i++) {
            if (A[i] == INT_MIN) continue;
            for (int j = 0; j + i < BUD; j++) {
                if (B[j] == INT_MIN) continue;
                merged[i + j] = max(merged[i + j], A[i] + B[j]);
            }
        }
        return merged;
    }

    pair<vector<int>, vector<int>> dfs(int u, int parent) {
        if (visited[u]) return memo[u];
        visited[u] = true;

        vector<int> noDiscount(budget + 1, 0);
        vector<int> withDiscount(budget + 1, 0);

        for (int v : tree[u]) {
            if (v == parent) continue;
            auto [childNo, childWith] = dfs(v, u);
            noDiscount = mergeDP(noDiscount, childNo);
            withDiscount = mergeDP(withDiscount, childWith);
        }

        vector<int> newDp0 = noDiscount;
        vector<int> newDp1 = noDiscount;

        // 1. Buy current node at full cost
        int fullCost = present[u];
        int profitFull = future[u] - fullCost;
        for (int b = fullCost; b <= budget; b++) {
            if (withDiscount[b - fullCost] != INT_MIN)
                newDp0[b] = max(newDp0[b],
                                withDiscount[b - fullCost] + profitFull);
        }

        // 2. Buy current node at half cost (parent discount)
        int halfCost = present[u] / 2;
        int profitHalf = future[u] - halfCost;
        for (int b = halfCost; b <= budget; b++) {
            if (withDiscount[b - halfCost] != INT_MIN)
                newDp1[b] = max(newDp1[b],
                                withDiscount[b - halfCost] + profitHalf);
        }

        return memo[u] = {newDp0, newDp1};
    }

    int maxProfit(
        int N,
        vector<int>& Present,
        vector<int>& Future,
        vector<vector<int>>& hierarchy,
        int Budget
    ) {
        n = N;
        budget = Budget;
        present = Present;
        future = Future;

        tree.assign(n, {});
        for (auto& e : hierarchy) {
            int u = e[0] - 1;
            int v = e[1] - 1;
            tree[u].push_back(v);
        }

        memo.resize(n);
        visited.assign(n, false);

        auto result = dfs(0, -1);
        return *max_element(result.first.begin(), result.first.end());
    }
};
