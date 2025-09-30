class Solution {
public:
    int distinctPoints(string s, int k) {
        int n = s.size();
        unordered_map<char, pair<int,int>> mp;
        mp['L'] = {-1,0};
        mp['R'] = {1,0};
        mp['U'] = {0,1};
        mp['D'] = {0,-1};

        
        vector<pair<int,int>> cd(n+1, {0,0});
        for (int i = 0; i < n; i++) {
            cd[i+1].first  = cd[i].first  + mp[s[i]].first;
            cd[i+1].second = cd[i].second + mp[s[i]].second;
        }

        set<pair<int,int>> st;
        for (int l = 0; l + k <= n; l++) {
            int r = l + k - 1;
            int fx = cd[l].first + (cd[n].first - cd[r+1].first);
            int fy = cd[l].second + (cd[n].second - cd[r+1].second);
            st.insert({fx, fy});
        }

        return st.size();
    }
};
