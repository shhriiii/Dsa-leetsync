class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int msum =nums[0];
        int csum =nums[0];
        for(int i =1;i<n;i++){
            // csum += nums[i];
            csum = max(nums[i] , csum+nums[i]);
            
            if(csum < 0) csum =nums[i];
            msum = max(csum , msum);
            
        }
        return msum;

        
    }
};