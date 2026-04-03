class Solution {
public:
    int neg = INT_MIN;
    int n , m;
    vector<vector<vector<int>>> dp;
    int solve(int i , int j , int k , vector<vector<int>>& coins){
        if(i<0 ||j<0 || i>=n || j>=m) return neg;
        if(dp[i][j][k] != neg) return dp[i][j][k];
        if(i==n-1 && j==m-1){
            int c =coins[i][j];
            if(c>=0){
                dp[i][j][k]=c;
            }
            else {
                dp[i][j][k] = (k > 0) ? max(c, 0) : c;
            }
            return dp[i][j][k];
        }
        
        int c = coins[i][j];
        int down = solve(i + 1, j, k, coins);
        int right = solve(i, j + 1, k, coins);
        int best = max(down, right);
         if (c >= 0) {
            dp[i][j][k] = c + best;
        } else {
            int pay = c + best;
            int skip = neg;

            if (k > 0) {
                int d2 = solve(i + 1, j, k - 1, coins);
                int r2 = solve(i, j + 1, k - 1, coins);
                skip = max(d2, r2);
            }

            dp[i][j][k] = max(pay, skip);
        }

        return dp[i][j][k];
    }
    int maximumAmount(vector<vector<int>>& coins) {
         n=coins.size();
        m =coins[0].size();
        dp.clear();
        dp.resize(n , vector<vector<int>>(m , vector<int>(3,neg)));
        return solve(0,0,2,coins);
        
        


        
    }
};