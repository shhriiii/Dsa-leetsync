class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();

        vector<int> ans;
        set<int> st;
        for(int i =0;i<n;i++){
            if(nums[i]<pivot){
                ans.push_back(nums[i]);
                // st.insert
            }
        }
        for(int i =0;i<n;i++){
            if(nums[i]==pivot){
                ans.push_back(nums[i]);
                // st.insert
            }
        }
        for(int i =0;i<n;i++){
            if(nums[i]>pivot){
                ans.push_back(nums[i]);
                // st.insert
            }
        }
        return ans;

        
    }
};