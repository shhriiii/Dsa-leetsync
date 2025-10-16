class Solution {
public:
    int findmax(set<int> st) {
        int val = 0;
        while (st.find(val) != st.end())
            val++;
        return val;
    }

    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            int mod = ((nums[i] % value) + value) % value;
            mp[mod]++;
        }

 
        set<int> st;
        for (auto &[mod, freq] : mp) {
            for (int i = 0; i < freq; i++) {
                st.insert(mod + i * value);
            }
        }

        return findmax(st);
    }
};
