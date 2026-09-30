class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        // inint lefttop =0 , leftbottom = n-1 , righttop = m-1 , rightbottom = n-1;
        vector<int> ans;
        int left = 0 , right = m-1 , top =0 , bottom = n-1;
        while(left <= right && top<=bottom ){
            for(int j =left ; j<= right ; j++){
                ans.push_back(matrix[top][j]);

            }
            top++;
            
            for(int i =top;i<=bottom;i++){
                ans.push_back(matrix[i][right]);
            }
            // bottom--;
            right--;
            if(top<=bottom){
            for(int j = right ; j>= left;j--){
                ans.push_back(matrix[bottom][j]);

            }
            }
            bottom--;
            if(left<=right){
            for(int i = bottom; i>=top;i--){
                ans.push_back(matrix[i][left]);
            }
            }
            left++;
        }
        return ans;


        
    }
};