class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pos;
        for (int i = 0; i < n; i++) {
            if (nums[i] >= 0) {
                pos.push_back(nums[i]);
            }
        }
        if(pos.size()>0){
        k= k % pos.size();
        reverse(pos.begin(), pos.begin() + k);
        reverse(pos.begin() + k, pos.end());
        reverse(pos.begin(), pos.end());
        }
        int j =0; 
        vector<int> ans(n);
        for(int i =0;i<n;i++){
            if(nums[i]<0){
                ans[i]=nums[i];
            }
            else{
                ans[i]=pos[j];
                j++;

            }

        }
        return ans;
    }
};