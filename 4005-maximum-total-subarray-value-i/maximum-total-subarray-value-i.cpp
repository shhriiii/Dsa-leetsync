#define ll long long
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int mxm = *max_element(nums.begin(),nums.end());
        
        int mnm = *min_element(nums.begin(),nums.end());
        ll diff = mxm - mnm;
        ll ans = diff*k;
        return ans;
        
    }
};