class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count =0;
        for(int i =0;i<n;i++){
            int low = 0 , high = m-1;
            int idx = -1;
            while(low<=high){
                int mid = low + (high-low)/2;
                if(grid[i][mid]<0){
                    idx = mid ;
                    high = mid-1;
                }
                else {
                    low = mid +1;
                }
            }
            if(idx!=-1){
                count += (m-idx);
            }
        }
        return count;
        
    }
};