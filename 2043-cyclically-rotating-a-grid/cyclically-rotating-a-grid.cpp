class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {

        int n = grid.size();
        int m = grid[0].size();

        int srow = 0;
        int scol = 0;

        while (srow < n / 2 && scol < m / 2) {

            int erow = n - srow - 1;
            int ecol = m - scol - 1;

            int total =
                2 * (erow - srow + 1) +
                2 * (ecol - scol + 1) - 4;

           int rotations = k % total;

            for (int j = 0; j < rotations; j++) {

                int temp1 = grid[srow][scol];

                // left column upward shift
                for (int crow = srow + 1; crow <= erow; crow++) {
                    int temp2 = grid[crow][scol];
                    grid[crow][scol] = temp1;
                    temp1 = temp2;
                }

                // bottom row left shift
                for (int ccol = scol + 1; ccol <= ecol; ccol++) {
                    int temp2 = grid[erow][ccol];
                    grid[erow][ccol] = temp1;
                    temp1 = temp2;
                }

                // right column downward shift
                for (int crow = erow - 1; crow >= srow; crow--) {
                    int temp2 = grid[crow][ecol];
                    grid[crow][ecol] = temp1;
                    temp1 = temp2;
                }

                // top row right shift
                for (int ccol = ecol - 1; ccol >= scol; ccol--) {
                    int temp2 = grid[srow][ccol];
                    grid[srow][ccol] = temp1;
                    temp1 = temp2;
                }
            }

            srow++;
            scol++;
        }

        return grid;
    }
};