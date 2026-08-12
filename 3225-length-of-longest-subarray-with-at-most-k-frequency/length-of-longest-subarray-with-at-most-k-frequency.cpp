class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int , int> mp;
        int i =0 , j =0;
        int maxLen=0;
        while(j<n){
                if(mp[nums[j]]<k){
                    mp[nums[j]]++;
                    j++;

                }
                else{
                    while(mp[nums[j]]>=k){
                        mp[nums[i]]--;
                        i++;
                    }
                }
                maxLen = max(maxLen,j-i);
            

        }
        maxLen = max(maxLen,j-i);
        return maxLen;
        
    }
};