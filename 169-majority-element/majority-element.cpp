class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int candidate = -1;
        int vote =0;
        for(int i =0;i<n;i++){
            if(vote==0){
                candidate = nums[i];
                vote++;

            }
            else{
                if(candidate==nums[i]) vote++;
                else {
                    vote--;
                }
            }
        }
        return candidate;
        
        
    }
};