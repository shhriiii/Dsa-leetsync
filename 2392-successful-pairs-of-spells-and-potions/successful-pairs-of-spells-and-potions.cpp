class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        vector<int> ans(n);
        sort(potions.begin(), potions.end());

        for (int i = 0; i < n; i++) {
            long long curr = spells[i];
            int low = 0, high = m - 1;
            int idx = m;

            while (low <= high) {
                int mid = low + (high - low) / 2;
                long long prod = curr * potions[mid];
                if (prod >= success) {
                    idx = mid;      
                    high = mid - 1;  
                } else {
                    low = mid + 1;
                }
            }

            ans[i] = m - idx;  
        }

        return ans;
    }
};
