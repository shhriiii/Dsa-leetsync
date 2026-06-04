class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        nums.insert(nums.begin(), INT_MIN);
nums.push_back(INT_MIN);
        n= nums.size();
        int low = 1 , high=nums.size()-2;
        while(low<=high){
            int mid = low+ (high-low)/2;
            if(mid-1>=0 && mid+1 <=n-1){
                if(nums[mid]>nums[mid-1] && nums[mid+1]<nums[mid]) return mid-1;
                else if(nums[mid]>nums[mid-1] && nums[mid+1]>nums[mid]) low=mid+1;
                else high=mid-1;
            }


        }
        return low;
        
    }
};