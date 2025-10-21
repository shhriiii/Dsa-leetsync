class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int maxLen =0;
        
        for(int i =0;i<n;i++){
            int co =0,ce =0;
            set<int> st;
            for(int j =i;j<n;j++){
                if(nums[j]%2==0 && !st.count(nums[j])){
                    ce++;
                    

                } 
                else if(nums[j]%2!=0 && !st.count(nums[j])) co++;
                st.insert(nums[j]);
                if(ce==co && ce!=0 && co!=0) maxLen = max(maxLen , j-i+1);
            }
        }
        return maxLen;
        
    }
};