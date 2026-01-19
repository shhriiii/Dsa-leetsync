#define ll long long

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();

        // 1-based prefix sum
        vector<vector<ll>> ps(n+1, vector<ll>(m+1, 0));

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                ps[i][j] = mat[i-1][j-1]
                         + ps[i-1][j]
                         + ps[i][j-1]
                         - ps[i-1][j-1];
            }
        }

        int ans = 0;

        // brute force all squares
        for(int len = 1; len <= min(n, m); len++){
            for(int i = len; i <= n; i++){
                for(int j = len; j <= m; j++){
                    ll sum = ps[i][j]
                           - ps[i-len][j]
                           - ps[i][j-len]
                           + ps[i-len][j-len];

                    if(sum <= threshold){
                        ans = max(ans, len);
                    }
                }
            }
        }
        return ans;
    }
};
