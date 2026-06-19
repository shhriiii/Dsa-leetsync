class Solution {
public:
    vector<vector<string>> ans;
    bool isValid(int n , vector<string>& box ,int i ,   int j){
        // check left -> j--
        // check left top i-- j--
        // check donw i++ , j--;
        int r=i-1 , c=j-1;
        // left
        for(int col = c;col>=0;col--){
            if(box[i][col]=='Q') return false;
        }
        while(r>=0 && c>=0){
            if(box[r][c]=='Q') return false;
            r--;
            c--;

        }
        r=i+1 , c=j-1;
        while(r<n && c>=0){
            if(box[r][c]=='Q') return false;
            r++;
            c--;


        }
        return true;
    }
    void helper(int n , vector<string>& box ,  int j){
        if(j==n) {
            ans.push_back(box);
            return;
        }


        for(int r=0;r<n;r++){
            if(box[r][j]=='.'){
                box[r][j]='Q';
                if(isValid(n, box , r , j)) helper(n,box,j+1);
                box[r][j]='.';
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        string s;
        for(int i =0;i<n;i++) s.push_back('.');
        vector<string> box;
        for(int i =0;i<n;i++) box.push_back(s);
        helper(n , box ,0);
        return ans;
        
        
    }
};