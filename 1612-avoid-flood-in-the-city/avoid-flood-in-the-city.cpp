class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        unordered_map<int, int> full;
        vector<int> ans(n,1);
        set<int> dry;
        for(int i =0;i<n;i++){
            int lake = rains[i];
            if(lake==0) dry.insert(i);
            else{
                ans[i]=-1;
                if(full.count(lake)){
                    auto it = dry.upper_bound(full[lake]);
                    if(it==dry.end()) return {};
                    ans[*it]=lake;
                    dry.erase(*it);
                }
                full[lake]=i;

            }
        }
        return ans;
        
    }
};