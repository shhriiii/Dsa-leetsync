class Solution {
public: 
    int n , m;
    void bfs(vector<vector<char>>& grid, vector<vector<int>>& vis , int i , int j ){
        queue<pair<int , int>> q;
        vis[i][j]=1;
        q.push({i,j});
        vector<vector<int>> dir = {{-1,0} , {1,0} , {0,-1} , {0,1}};
        while(!q.empty()){
            auto [r , c] = q.front();
            q.pop();
            for(int d=0;d<4;d++){
                int nr = r + dir[d][0];
                int nc =c + dir[d][1];
                if(nr >=0 && nr < n && nc >=0 && nc<m && grid[nr][nc]=='1' && vis[nr][nc]==0 ){
                    q.push({nr,nc});
                    vis[nr][nc]=1;

                }
            }
        }
        return;

    }
    int numIslands(vector<vector<char>>& grid) {
         n = grid.size();
        m = grid[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]=='0') vis[i][j]=1;


            }
        }
        int count=0;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]=='1' && vis[i][j]==0){
                    bfs(grid , vis , i , j);
                    count++;
                }
            }
        }
        return count;
        
    }
};