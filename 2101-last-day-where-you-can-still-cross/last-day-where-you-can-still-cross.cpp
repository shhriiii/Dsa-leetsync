class Solution {
public:
    int rs, cs;
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

    bool canCross(int day, vector<vector<int>>& cells) {
        vector<vector<int>> grid(rs, vector<int>(cs, 0));

        // flood cells till 'day'
        for (int i = 0; i <= day; i++) {
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;
            grid[r][c] = 1;
        }

        queue<pair<int,int>> q;

        // start BFS from top row
        for (int j = 0; j < cs; j++) {
            if (grid[0][j] == 0) {
                q.push({0, j});
                grid[0][j] = 1; // mark visited
            }
        }

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (r == rs - 1) return true;

            for (auto &d : dir) {
                int nr = r + d[0];
                int nc = c + d[1];

                if (nr >= 0 && nc >= 0 && nr < rs && nc < cs && grid[nr][nc] == 0) {
                    grid[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        rs = row;
        cs = col;

        int low = 0, high = cells.size() - 1;
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canCross(mid, cells)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans+1;
    }
};
