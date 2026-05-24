class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st(nums.begin(),nums.end());
        // cout<<st.size();
        int i =0;
        for(auto & it : st){
            nums[i]=it;
            i++;
        }
        return st.size();
        
    }
};