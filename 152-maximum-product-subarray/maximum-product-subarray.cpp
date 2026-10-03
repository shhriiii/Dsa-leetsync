class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxTillNow = nums[0];
        int minTillNow = nums[0];
        int mx = nums[0];
        for(int i =1;i<n;i++){
            
            int temp = maxTillNow;
            maxTillNow = max({maxTillNow*nums[i],nums[i],minTillNow*nums[i]});
            minTillNow = min({minTillNow*nums[i],nums[i],temp*nums[i]});
            mx = max({maxTillNow,minTillNow,mx});
            

        }
        return mx;

        
    }
};