

class Solution {
public:
    double dist(vector<int>& a, vector<int>& b) {
        return sqrt((a[0] - b[0]) * 1.0 * (a[0] - b[0]) +
                    (a[1] - b[1]) * 1.0 * (a[1] - b[1]));
    }
    
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double maxArea = 0.0;

        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                for (int k = j+1; k < n; k++) {
                    double a = dist(points[i], points[j]);
                    double b = dist(points[j], points[k]);
                    double c = dist(points[i], points[k]);

                    double s = (a + b + c) / 2.0;
                    double area = sqrt(max(0.0, s * (s - a) * (s - b) * (s - c)));
                    
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};
