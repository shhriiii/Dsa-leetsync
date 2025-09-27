class Solution {
public:
    int helper(int i, int n, vector<int>& costs, vector<int>& dp) {
        if (i == n) return 0; 
        if (dp[i] != -1) return dp[i];

        int ans = INT_MAX;

        for (int k = 1; k <= 3 && i + k <= n; k++) {
            int jumpCost = costs[i + k] + (k * k);
            int next = helper(i + k, n, costs, dp);
            ans = min(ans, jumpCost + next);
        }

        return dp[i] = ans;
    }

    int climbStairs(int n, vector<int>& costs) {
     
        costs.insert(costs.begin(), 0);

        vector<int> dp(n + 1, -1);
        return helper(0, n, costs, dp);
    }
};
