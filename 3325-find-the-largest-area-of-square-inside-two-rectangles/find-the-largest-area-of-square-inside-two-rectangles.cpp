class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& l, vector<vector<int>>& r) {
        int n = l.size();
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                int left   = max(l[i][0], l[j][0]);
                int right  = min(r[i][0], r[j][0]);
                int bottom = max(l[i][1], l[j][1]);
                int top    = min(r[i][1], r[j][1]);

                if (left < right && bottom < top) {
                    long long side = min(right - left, top - bottom);
                    ans = max(ans, side * side);
                }
            }
        }
        return ans;
    }
};
