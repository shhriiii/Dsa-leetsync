class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<vector<int>> comb(3);
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            int mod = nums[i] % 3;
            comb[mod].push_back(nums[i]);
        }
        int first = 0;
        if (comb[0].size() >= 3) {
            int m = comb[0].size();
            first = comb[0][m - 1] + comb[0][m - 2] + comb[0][m - 3];
        }
        int second = 0;
        if (comb[1].size() >= 3) {
            int m = comb[1].size();
            second = comb[1][m - 1] + comb[1][m - 2] + comb[1][m - 3];
        }
        int third = 0;
        if (comb[2].size() >= 3) {
            int m = comb[2].size();
            third = comb[2][m - 1] + comb[2][m - 2] + comb[2][m - 3];
        }
        int fourth = 0;
        if (comb[1].size() >= 1 && comb[0].size() >= 1 && comb[2].size() >= 1) {
            int m = comb[0].size();
            int a = comb[1].size();
            int b = comb[2].size();

            fourth = comb[0][m - 1] + comb[1][a - 1] + comb[2][b - 1];
        }
        return max({first , second , third , fourth});
    }
};