class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int c = n;
        vector<int> curr=nums;
        while(c>1){
            vector<int> a;
            
            for(int i =0;i<c-1;i++){
                a.push_back((curr[i]+curr[i+1])%10);
            }
            c--;
            curr=a;

        }
        return curr[0];
        
    }
};