class Solution {
public:
    int mod = 1e9 + 7;
    // int expo(int base , int p){
    //     long long ans =1;
    //     long long b =base%mod;
    //     while(p>0){

    //     }

    // }
    long long power(long long a, long long b) {
        if (b == 0)
            return 1;

        long long half = power(a, b / 2) %mod;

        if (b % 2 == 0) {
            return (half * half)%mod;
        }

        return (half * half * a)%mod;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n + 2);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        int level = 0;
        queue<int> q;
        q.push(1);
        // vector<int> vis(n+1,0);

        vector<int> vis(n + 2, 0);

        vis[1] = 1;

        // int level = 0;

        while (!q.empty()) {
            int m = q.size();

            for (int i = 0; i < m; i++) {
                int node = q.front();
                q.pop();

                for (auto& ngbr : adj[node]) {
                    if (!vis[ngbr]) {
                        vis[ngbr] = 1;
                        q.push(ngbr);
                    }
                }
            }

            level++;
        }
        int ans = 0;
        level -= 2;
        if (level < 0)
            return 0;
        return (int)power(2, level) % mod;
    }
};
