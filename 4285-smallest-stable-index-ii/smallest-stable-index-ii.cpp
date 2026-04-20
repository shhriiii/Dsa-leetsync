class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> mxm(n);
        vector<int> mnm(n);
        mxm[0]=nums[0];
        int mx = nums[0];
        for(int i =1;i<n;i++){
            mx = max(nums[i],mx);
            mxm[i]=mx;

        }
        int mn=nums[n-1];
        mnm[n-1]=nums[n-1];
        for(int i =n-2;i>=0;i--){
            mn=min(mn,nums[i]);
            mnm[i]=mn;

        }
        // vector<int> stable;
        for(int i=0;i<n;i++){
            int score = mxm[i]-mnm[i];
            if(score<=k) return i;

        }
        return -1;
        
    }
};