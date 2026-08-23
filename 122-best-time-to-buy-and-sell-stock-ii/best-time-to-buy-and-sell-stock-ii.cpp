class Solution {
public:
    int n ;
    vector<vector<int>> dp;
    int helper(vector<int>& prices , int turn , int idx){
        if(idx>=n){
            return 0;

        }
        if(dp[idx][turn]!=-1) return dp[idx][turn];
        //buy
        if(turn == 0) {
            return dp[idx][turn] = max(-prices[idx]+helper(prices , 1 , idx+1),helper(prices , 0 , idx+1));
        }
        else{
            return dp[idx][turn] = max(prices[idx]+helper(prices , 0 , idx+1),helper(prices , 1 , idx+1));
        }
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        dp.resize(n,vector<int>(2,-1));
        return helper(prices, 0 , 0);

        
    }
};