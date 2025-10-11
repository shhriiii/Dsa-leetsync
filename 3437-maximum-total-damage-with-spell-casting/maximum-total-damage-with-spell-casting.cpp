class Solution {
public:
 unordered_map<long long ,long long> mp;
 vector<long long> dp;
  
    long long helper(vector<long long>& nums , long long i){
        long long n = nums.size();
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];

        auto it = lower_bound(nums.begin(), nums.end(), nums[i]+3);
        long long index = it - nums.begin();
        long long freq = mp[nums[i]];
        long long pick = freq*nums[i]+helper(nums, index);
        long long skip = helper(nums , i+1);


        return dp[i]= max(pick,skip);


        
    }
    long long maximumTotalDamage(vector<int>& power) {
       long long n = power.size();
       sort(power.begin(),power.end());
       dp.resize(n,-1);
      
       for(long long i =0;i<n;i++){
        mp[power[i]]++;
       }
       vector<long long> nums;
       nums.push_back(power[0]);
       for(long long i =1;i<n;i++){
        if(power[i]!=power[i-1]) nums.push_back(power[i]);

       }
       return helper(nums , 0); 
        
    }
};