class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        // pls see striver video to know why
        //  instead of extra mtrix for col and row we use the first col and first row to track if there is any zero in tht row or col , after tht only chck all the row and col except first col and row 
        // after tht chck in order first check the first colmn then chck first col else it will affect the answer for better explnation pls see striver video from 14 : 00 time stamp 
        int col0=1;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    if(j!=0){
                        matrix[0][j]=0;
                    }
                    else col0=0;
                }
            }
        }
        for(int i = 1;i<n;i++){
            for(int j =1;j<m;j++){
                if(matrix[i][j]!=0){
                    if(matrix[i][0]==0 || matrix[0][j]==0){
                        matrix[i][j]=0;
                    }
                }
            }
        }
        if(matrix[0][0]==0){
            for(int j = 0;j<m;j++){
                matrix[0][j]=0;
            }
        }
        if(col0==0){
            for(int i =0;i<n;i++){
                matrix[i][0]=0;
            }
        }
        // return matrix;

        
    }
};