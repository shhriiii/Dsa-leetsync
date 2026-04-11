class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int , vector<int>> mp;
        int dist = INT_MAX;
        int n = nums.size();
        for(int i =0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        for(auto & it : mp){
            vector<int>& curr = it.second;
            if(curr.size()<3) continue;
            int x = curr.size();
            int i =0;
            while(i+2<=x-1){
                dist=min(abs(curr[i]-curr[i+1])+abs(curr[i+1]-curr[i+2])+abs(curr[i+2]-curr[i]),dist);
                i++;
            }

        }
        if(dist==INT_MAX) return -1;
        return dist;
    }
};