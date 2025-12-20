class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int , int> mp;
        int n = nums.size();
        for(int i =0;i<n;i++){
            mp[nums[i]]++;

        }
        if(mp.size()==n) return 0;
        int count=0;
        bool found =false;
        for(int i =0;i<n;i++){
            mp[nums[i]]--;
            if(mp[nums[i]]==0){
                mp.erase(nums[i]);
            }
            if(i%3==2){
                count++;
                int rem = n-i-1;
                if(rem== mp.size()) {
                    found=true;
                    break;
                }
            }

        }
        if(found) return count;
        else{
            return count + 1;
        }
        
    }
};