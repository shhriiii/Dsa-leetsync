class Solution {
public:
    int dir[4][4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>
            pq;
        pq.push({grid[0][0], {0, 0}});
        vector<vector<int>> vis(n, vector<int>(n, 0));
        vis[0][0]=1;
        while (!pq.empty()) {
            auto [time, co] = pq.top();
            pq.pop();
            int x = co.first;
            int y = co.second;
            if(x==n-1 && y==n-1) return time;
            for (int d = 0; d < 4; d++) {
                int nx = x + dir[d][0];
                int ny = y + dir[d][1];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && !vis[nx][ny]) {
                    vis[nx][ny] = 1;

                    pq.push({max(time, grid[nx][ny]), {nx, ny}});

                }
            }
        }
        return 0;
    }
};