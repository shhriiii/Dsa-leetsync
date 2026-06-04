class Solution {
public:
    int n;
    int mini;
    vector<int> freeItems;
    vector<vector<int>> dp;

    int solve(vector<vector<int>>& items, int budget, int idx) {

        if (idx >= n)
            return budget / mini;

        if (dp[idx][budget] != -1)
            return dp[idx][budget];

        int pick = 0;

        if (items[idx][1] <= budget) {
            pick = freeItems[idx] +
                   solve(items,
                         budget - items[idx][1],
                         idx + 1);
        }

        int notPick = solve(items, budget, idx + 1);

        return dp[idx][budget] = max(pick, notPick);
    }

    int maximumSaleItems(vector<vector<int>>& items, int budget) {

        n = items.size();

        mini = 1e9;
        freeItems.resize(n);

        for (int i = 0; i < n; i++) {

            mini = min(mini, items[i][1]);

            int cnt = 0;

            for (int j = 0; j < n; j++) {

                if (items[j][0] % items[i][0] == 0)
                    cnt++;
            }

            freeItems[i] = cnt;
        }

        dp.assign(n + 1, vector<int>(budget + 1, -1));

        return solve(items, budget, 0);
    }
};