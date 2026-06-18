class Solution {
public:
    int n, m;
           vector<vector<int>> dir;
    

    bool helper(vector<vector<char>>& board, string word , int i ,int j ,vector<vector<int>> & vis , int idx ){
        if(i >= n || j >= m || i < 0 || j < 0 || vis[i][j] == 1 || board[i][j] != word[idx]) {
            return false;
        }
        
        // 2. BASE CASE: If we just matched the last character of the word, we are done!
        // This completely fixes the 1x1 grid and 1-letter word issue.
        if(idx == word.length() - 1) {
            return true;
        }
        vis[i][j]=1;
        if(board[i][j]==word[idx]){
            for(int d =0;d<4;d++){
                int nr = i + dir[d][0];
                int nc = j + dir[d][1];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc]){
                   if (helper(board, word, nr, nc, vis, idx + 1)) return true;
                }
            }
        }
         vis[i][j]=0;
        return false;
    }


    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
 
    dir.push_back({0,1});
    dir.push_back({1,0});
    dir.push_back({0,-1});
    dir.push_back({-1,0});
       
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(board[i][j]==word[0]){
                     vector<vector<int>> vis(n,vector<int>(m,0));
                    if (helper(board, word, i, j, vis, 0)) return true;
                }
            }
        }
        return false;


        
    }
};