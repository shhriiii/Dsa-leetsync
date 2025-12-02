class Solution {
public:
    int mod = 1e9 + 7;

    long long C2(long long k) {
        if (k < 2) return 0;
        return (k * (k - 1) / 2) % mod;
    }

    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[points[i][1]].push_back(points[i][0]);
        }

        vector<int> uniY;
        for (auto &it : mp) uniY.push_back(it.first);

        int m = uniY.size();
        if (m <= 1) return 0;
        vector<long long> L;
        L.reserve(m);

        for (int y : uniY) {
            int k = mp[y].size();
            L.push_back(C2(k));
        }

        long long S1 = 0, S2 = 0;
        for (long long x : L) {
            S1 = (S1 + x) % mod;
            S2 = (S2 + (x * x) % mod) % mod;
        }
        long long result = ( ( (S1 * S1) % mod - S2 + mod ) % mod ) * 500000004LL % mod;  


        return result;
    }
};
