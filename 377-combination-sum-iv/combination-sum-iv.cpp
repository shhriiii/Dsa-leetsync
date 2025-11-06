class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int helper(vector<int>& nums, int target , int currSum , int idx){
        if(currSum > target || idx >= n) return 0;
        if(currSum == target) return 1;

        if(dp[currSum][idx] != -1) return dp[currSum][idx];

        int pick = helper(nums , target , currSum + nums[idx] , 0);

        int notPick = helper(nums , target , currSum , idx+1);

        return dp[currSum][idx] = pick + notPick;
    }

    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();
        dp.assign(target + 1, vector<int>(n, -1));
        return helper(nums , target , 0 , 0);
    }
};
