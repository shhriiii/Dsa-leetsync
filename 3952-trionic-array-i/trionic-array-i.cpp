class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        bool p = false, q = false, r = true;
        int n = nums.size();
        if (n == 3)
            return false;
        int pidx = -1, qidx = -1, ridx = -1;
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                pidx = i;
                p = true;
                break;
            }
            if (nums[i] == nums[i + 1]) {
                return false;
            }
        }
        if (p) {
            for (int i = pidx + 1; i < n - 1; i++) {
                if (nums[i] < nums[i + 1]) {
                    qidx = i;
                    q = true;
                    break;
                }
                if (nums[i] == nums[i + 1]) {
                    return false;
                }
            }
        }
        if (q) {
            for (int i = qidx + 1; i < n; i++) {
                if (nums[i - 1] >= nums[i]) {
                    r = false;
                    break;
                }
            }
        }
        // if
        if (q && p && r && pidx > 0)
            return true;
        return false;
    }
};