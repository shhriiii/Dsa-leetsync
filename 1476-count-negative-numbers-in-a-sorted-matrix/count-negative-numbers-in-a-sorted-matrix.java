class Solution {
    public int countNegatives(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        int count =0;
        for(int i =0;i<n;i++){
            int low = 0 , high =m-1;
            int idx = -1;
            while(low<=high){
                int mid = low + (high-low)/2;
                if(grid[i][mid]<0){
                    high=mid-1;
                    idx = mid;

                }
                else low = mid +1;
            }
            if(idx!=-1) count +=(m-idx);

        }   
        return count;     
        
    }
}