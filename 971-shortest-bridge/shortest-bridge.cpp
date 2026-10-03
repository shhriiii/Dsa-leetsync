class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<pair<int, int>, int>> q;
        queue<pair<int, int>> qq;
        bool found = false;
        //  point to be noted is tht the bfs is done once only so overall tc would be n^2 not n^4
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && vis[i][j] == 0) {
                    vis[i][j] = 1;
                    found=true;

                    q.push({{i, j}, 0});
                    qq.push({i, j});
                    while (!qq.empty()) {
                        auto [ci, cj] = qq.front();

                        qq.pop();
                        for (int d = 0; d < 4; d++) {
                            int ni = ci + dir[d][0];
                            int nj = cj + dir[d][1];
                            if (ni >= 0 && nj >= 0 && ni < n && nj < n &&
                                grid[ni][nj] && !vis[ni][nj]) {
                                vis[ni][nj] = 1;
                                qq.push({ni, nj});
                                q.push({{ni, nj}, 0});
                            }
                        }
                    }
                    break;
                }
            }
            if(found) break;
            
        }
        while (!q.empty()) {
            auto [cell,dist] = q.front();
            int ci = cell.first;
            int cj = cell.second;
            q.pop();
            //  ngbr is 1 , alrdy vis continue
            //  ngbr is 0 , insert it do +1 in dist
            // ngbr is 1 and is unvisited return d+1;
            for (int d = 0; d < 4; d++) {
                int ni = ci + dir[d][0];
                int nj = cj + dir[d][1];
                if (ni >= 0 && nj >= 0 && ni < n && nj < n && !vis[ni][nj]) {
                    vis[ni][nj] = 1;
                    if(grid[ni][nj]==0){
                        q.push({{ni,nj},dist+1});

                    }
                    
                    else{
                        return dist;

                    }
                }
            }
        }
        return 0;
    }
};
// 1 1 1 1
// 0 0 0 0
// 0 0 0 1
// 0 0 1 1