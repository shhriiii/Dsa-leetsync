class Solution {
public:
int n;
    int helper(vector<int>& nums, int target , int idx , int curr){
        if(idx>=n){
            if(curr==target) return 1;
            return 0;
        }
        // if( idx == n-1){
        //     if(curr+nums[idx] == target || curr - nums[idx] == target ) return 1;
        //     return 0;
        // }
        int add = helper(nums , target , idx+1 , curr+nums[idx]);
        int subs = helper(nums , target , idx+1 , curr - nums[idx]);
        return add+subs;
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
       return  helper(nums , target , 0 , 0);
        

        
    }
};