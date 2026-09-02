class Solution {
public:
    int n;
    vector<vector<int>> dp;
bool isPred(string& old, string& curr) {

        // A predecessor must be exactly 1 character shorter
        if (old.size() + 1 != curr.size()) {
            return false;
        }

        int i = 0, j = 0;

        while (i < old.size() && j < curr.size()) {

            if (old[i] == curr[j]) {
                i++;
            }

            j++;
        }

        return i == old.size();
    }
    int helper(vector<string>& words, int idx, int prev) {
        if (idx >= n) {
            return 0;
        }
        int pick = 0;
        if(dp[idx][prev+1]!=-1) return dp[idx][prev+1];
        if (prev == -1 || isPred(words[prev],words[idx])) {
            pick = 1 + helper(words, idx + 1,idx);
        }

        int notPick = helper(words, idx + 1, prev);

        return  dp[idx][prev+1] = max(pick, notPick);
    }
    int longestStrChain(vector<string>& words) {
        n = words.size();

        sort(words.begin(), words.end(),
             [](string& a, string& b) {
                 return a.size() < b.size();
             });
        dp.clear();
        dp.resize(n+1,vector<int>(n+2,-1));
        return helper(words, 0, -1);
    }
};