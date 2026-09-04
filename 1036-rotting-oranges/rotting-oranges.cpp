class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dir = {{0,1} , {0,-1} , {-1,0} , {1,0}};
        queue<pair<int , pair<int , int>>> q;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]==1){
                    vis[i][j]=1;
                }
                else if(grid[i][j]==2){
                    vis[i][j]==2;
                    q.push({0,{i,j}});
                }
            }
        }
        int maxTime =0;
        while(!q.empty()){
            int currTime = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            maxTime = max(maxTime , currTime);
            for(int d =0;d<4;d++){
                int nrow = row + dir[d][0];
                int ncol = col + dir[d][1];
                if(nrow >=0 && nrow < n && ncol >=0 && ncol < m && vis[nrow][ncol]==1){
                    vis[nrow][ncol]=2;
                    q.push({currTime+1 ,{nrow,ncol}});
                }
            }

        }
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(vis[i][j]==1){
                return -1;
                }
                
            }
        }
        

        return maxTime;
        
    }
};