class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double totalArea = 0;
        for (auto& square : squares) {
            double side = square[2];  
            totalArea += side * side;  
        }
        
        double targetArea = totalArea / 2.0;  
        vector<double> yCoords;
        for (auto& square : squares) {
            yCoords.push_back(square[1]);          
            yCoords.push_back(square[1] + square[2]); 
        }
        double low = *min_element(yCoords.begin(), yCoords.end());
        double high = *max_element(yCoords.begin(), yCoords.end());
        double eps = 1e-5; 

        while (high - low > eps) {
            double mid = (low + high) / 2.0;
            double areaAboveMid = 0;

            for (auto& square : squares) {
                int x = square[0];
                double y = square[1], l = square[2];  

                if (y + l <= mid) continue; 
                if (y >= mid) { 
                    areaAboveMid += (double)l * l; 
                } else {
                    double heightAbove = (y + l) - mid;
                    areaAboveMid += heightAbove * l;  
                }
            }
            if (areaAboveMid > targetArea)
                low = mid; 
            else
                high = mid; 
        }
        return low;  
    }
};
