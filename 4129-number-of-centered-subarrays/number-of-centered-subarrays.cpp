class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n = nums.size();
        int count =0;
        for(int i =0;i<n;i++){
            set<int> st;
            int sum = 0;

            for(int j = i ; j<n;j++){
                sum+=nums[j];
                st.insert(nums[j]);
                if(st.find(sum)!=st.end()) count++;


            }
        }
        return count;
        
    }
};