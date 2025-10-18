class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int , int> mp;
        for(int i =0;i<n;i++){
            mp[nums[i]]++;

        }
   
        // freq, val

        priority_queue<pair<int ,int> , vector<pair<int,int>> , greater<pair<int , int>>> pq;
        for(auto it : mp){
            pq.push({it.second , it.first});
        }
        while(k >0){
            auto [freq , val] = pq.top();
            pq.pop();
            int curr = min(freq,k);
            k-= curr;
            freq-= curr;
            
            if(k==0 && freq > 0){
                pq.push({freq , val});
            }

        }
        return pq.size();
        
    }
};
