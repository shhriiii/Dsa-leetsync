class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = 1e9;
        for(int i=0;i<n;i++){
            int mnm = nums[i];
            long long val = 1LL*mnm*k;
            int it = upper_bound(nums.begin(),nums.end(),val)-nums.begin();
            // if(it<n){
            ans = min(ans , n-it+i);
            // }

        }
        if(ans==1e9) return 0;
        return ans;

        
    }
};