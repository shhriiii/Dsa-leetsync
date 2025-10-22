class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int no) {
         int n = nums.size();
    
        unordered_map<int, int> freq;
        for (int x : nums) {
            freq[x]++;
        }


        sort(nums.begin(), nums.end());


        set<long long> candidates;
        for (int x : nums) {
            candidates.insert((long long)x);
            candidates.insert((long long)x - k);
            candidates.insert((long long)x + k);
        }

        int mxm = 0; 
        for (long long T : candidates) {
            long long lhs = T - k;
            long long rhs = T + k;
            auto it_r = upper_bound(nums.begin(), nums.end(), rhs);
            auto it_l = lower_bound(nums.begin(), nums.end(), lhs);

            int total_changeable = it_r - it_l;

            int C1 = 0;
            if (T >= INT_MIN && T <= INT_MAX && freq.count((int)T)) {
                C1 = freq.at((int)T);
            }
            int C2 = total_changeable - C1;


            int final_freq = C1 + min(no, C2);

            mxm = max(mxm, final_freq);
        }

        return mxm;
        
    }
};