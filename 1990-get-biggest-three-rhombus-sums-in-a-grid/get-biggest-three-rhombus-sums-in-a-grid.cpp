class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        set<int> ans;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                ans.insert(grid[i][j]);
                for (int k = 1;k<n && k<m ; k++) {
                    if (i - k < 0 || i + k >= n || j - k < 0 || j + k >= m)
                        break;

                    int sum = 0;
                    sum += grid[i - k][j];

                    for (int d = 1; d <= k; d++)
                        sum += grid[i - k + d][j + d];
                    for (int d = 1; d <= k; d++)
                        sum += grid[i + d][j + k - d];

                    for (int d = 1; d <= k; d++)
                        sum += grid[i + k - d][j - d];
                    for (int d = 1; d < k; d++)
                        sum += grid[i - d][j - k + d];

                    ans.insert(sum);
                }
            }
        }

        vector<int> ret;
        for (auto it = ans.rbegin(); it != ans.rend() && ret.size() < 3; ++it) {
            ret.push_back(*it);
        }

        return ret;
    }
};