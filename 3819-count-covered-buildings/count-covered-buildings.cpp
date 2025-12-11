class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {

        map<int, vector<int>> ytox;
        map<int, vector<int>> xtoy;

        for (auto &b : buildings) {
            int x = b[0];
            int y = b[1];
            ytox[y].push_back(x);
            xtoy[x].push_back(y);
        }
        for (auto &p : ytox) sort(p.second.begin(), p.second.end());
        for (auto &p : xtoy) sort(p.second.begin(), p.second.end());

        int count = 0;

        for (auto &b : buildings) {
            int x = b[0];
            int y = b[1];

            auto &row = ytox[y]; 
            auto &col = xtoy[x]; 

            int xi = lower_bound(row.begin(), row.end(), x) - row.begin();

            int yi = lower_bound(col.begin(), col.end(), y) - col.begin();

            bool left = (xi - 1 >= 0);
            bool right = (xi + 1 < row.size());
            bool down = (yi - 1 >= 0);
            bool up = (yi + 1 < col.size());

            if (left && right && up && down) count++;
        }

        return count;
    }
};
