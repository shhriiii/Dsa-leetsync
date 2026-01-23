class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {

        int count = 0;

        // Keep doing operations
        while (true) {

            // Check if already non-decreasing
            bool sorted = true;
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] < nums[i - 1]) {
                    sorted = false;
                    break;
                }
            }

            if (sorted) break;

            // Find adjacent pair with minimum sum
            int minSum = INT_MAX;
            int idx = -1;

            for (int i = 0; i + 1 < nums.size(); i++) {
                int s = nums[i] + nums[i + 1];

                if (s < minSum) {
                    minSum = s;
                    idx = i;
                }
            }

            // Merge at idx
            nums[idx] = nums[idx] + nums[idx + 1];
            nums.erase(nums.begin() + idx + 1);

            count++;
        }

        return count;
    }
};
