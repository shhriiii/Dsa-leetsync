class Solution {
public:
    int mod = 1e9 + 7;

    int countPaths(int n, vector<vector<int>>& roads) {
       
        vector<vector<pair<int,int>>> adj(n);
        for (auto &road : roads) {
            int u = road[0], v = road[1], t = road[2];
            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();

            if (time > dist[node]) continue; 

            for (auto &[ngbr, wt] : adj[node]) {
                long long newTime = time + wt;

                if (newTime < dist[ngbr]) {
                    dist[ngbr] = newTime;
                    ways[ngbr] = ways[node]; 
                    pq.push({newTime, ngbr});
                }
                else if (newTime == dist[ngbr]) {
                    ways[ngbr] = (ways[ngbr] + ways[node]) % mod;
                }
            }
        }

        return ways[n-1] % mod;
    }
};
