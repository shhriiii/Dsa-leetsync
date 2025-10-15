class Solution {
public:
    bool isPossible(vector<int>& inc, int size) {
        int n = inc.size();
        if (size == 0) return false;      
        if (2 * size > n) return false;   
        int i = 0;
        int j = i + size;
        bool isok = false;

        while (j + size - 1 < n) {
            int valI = inc[j - 1];
            int valJ = inc[j + size - 1];
            if (valI >= size && valJ >= size) {
                isok = true;
                break;
            }
            i++;
            j++;
        }

        return isok;
    }

    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> inc(n);
        inc[0] = 1;
        int count = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1])
                inc[i] = ++count;
            else
                inc[i] = count = 1;
        }

        int low = 1, high = n, ans = 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(inc, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};

