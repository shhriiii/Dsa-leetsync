class Solution {
public:
    vector<int> size, parent;
    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] > size[ulp_v]) {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        } else {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxX = -1;
        int maxY = -1;
        for (int i = 0; i < n; i++) {
            maxX = max(maxX, stones[i][0]);
            maxY = max(maxY, stones[i][1]);
        }
        unordered_set<int> stoneNode;
        parent.resize(maxX + maxY + 2);
        size.resize(maxX + maxY + 2);

        for (int i = 0; i <= maxX + maxY + 1; i++) {
            parent[i] = i;
            size[i] = 1;
        }
        for (auto& it : stones) {
            int x = it[0];
            int y = it[1] + maxX+1;
            unionBySize(x, y);
            stoneNode.insert(x);
            stoneNode.insert(y);
        }
        int c = 0;
        for (int node : stoneNode) {
            if (findUPar(node) == node) {
                c++;
            }
        }
        return stones.size() - c;
    }
};