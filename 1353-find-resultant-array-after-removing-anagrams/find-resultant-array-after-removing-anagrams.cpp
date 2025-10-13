class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        string prev = "";
        
        for (auto& w : words) {
            string sortedW = w;
            sort(sortedW.begin(), sortedW.end());
            
            if (sortedW != prev) {
                ans.push_back(w);
                prev = sortedW;
            }
        }
        
        return ans;
    }
};
