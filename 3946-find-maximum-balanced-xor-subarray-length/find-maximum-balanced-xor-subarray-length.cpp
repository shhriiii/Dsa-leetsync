class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        int n = nums.size();

        // mp[xor][balance] = earliest index
        unordered_map<int, unordered_map<int,int>> mp;

        int xrr = 0, odd = 0, even = 0;
        int maxLen = 0;

        // Before starting
        mp[0][0] = -1;

        for (int i = 0; i < n; i++) {

            // update xor
            xrr ^= nums[i];

            // update odd/even
            if (nums[i] % 2 == 0) even++;
            else odd++;

            // difference same as your (currE == currO) logic
            int balance = even - odd;

            // if same (xor, balance) seen before → valid subarray
            if (mp[xrr].count(balance)) {
                maxLen = max(maxLen, i - mp[xrr][balance]);
            } 
            else {
                // store earliest index
                mp[xrr][balance] = i;
            }
        }

        return maxLen;
    }
};
