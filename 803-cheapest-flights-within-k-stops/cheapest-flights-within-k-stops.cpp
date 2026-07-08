class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < flights.size(); i++) {
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>> pq;

        pq.push({0, {src, 0}});

        // FIX: dist should depend on both node and steps
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        dist[src][0] = 0;

        while (!pq.empty()) {
            int wt = pq.top().first;
            int node = pq.top().second.first;
            int steps = pq.top().second.second;
            pq.pop();

            // FIX: destination can be reached using at most k+1 flights
            if (node == dst)
                return wt;

            // FIX: cannot take more than k+1 flights
            if (steps == k + 1)
                continue;

            for (auto it : adj[node]) {
                int adjNode = it.first;
                int edgeWt = it.second;

                // FIX: compare using steps+1
                if (wt + edgeWt < dist[adjNode][steps + 1]) {
                    dist[adjNode][steps + 1] = wt + edgeWt;
                    pq.push({wt + edgeWt, {adjNode, steps + 1}});
                }
            }
        }

        return -1;
    }
};