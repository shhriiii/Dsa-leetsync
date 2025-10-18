class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        

        int prevMax = nums[0]-k;
        vector<int> ans(n);
        ans[0]=prevMax;
        for(int i =1;i<n;i++){
            int curr = prevMax+1;
            if(curr >= nums[i] - k && curr <= nums[i]+ k){
                ans[i]=curr;
                prevMax=curr;
            }
            else {
                prevMax = max(prevMax , nums[i]-k);
                ans[i]=prevMax;
            }


        }
        set<int> s(ans.begin(),ans.end());
        return s.size();
        
        
    }
};