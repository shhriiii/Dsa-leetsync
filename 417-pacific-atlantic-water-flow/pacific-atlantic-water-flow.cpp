#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m, n;
    vector<vector<int>> h;
    int dirs[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};

    void dfs(int i, int j, vector<vector<int>> &vis) {
        vis[i][j] = 1;

        for (auto &d : dirs) {
            int ni = i + d[0], nj = j + d[1];
     
            if (ni >= 0 && nj >= 0 && ni < m && nj < n &&
                !vis[ni][nj] && h[ni][nj] >= h[i][j]) {
                dfs(ni, nj, vis);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        h = heights;
        m = h.size();
        n = h[0].size();

        vector<vector<int>> pac(m, vector<int>(n, 0));
        vector<vector<int>> atl(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) dfs(i, 0, pac);        // left column
        for (int j = 0; j < n; j++) dfs(0, j, pac);        // top row

       
        for (int i = 0; i < m; i++) dfs(i, n - 1, atl);    // right column
        for (int j = 0; j < n; j++) dfs(m - 1, j, atl);    // bottom row

    
        vector<vector<int>> ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pac[i][j] && atl[i][j])
                    ans.push_back({i, j});
            }
        }

        return ans;
    }
};
