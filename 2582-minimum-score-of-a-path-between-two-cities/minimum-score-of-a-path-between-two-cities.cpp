class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,int>>> adj(n + 1);

        for (auto &r : roads) {
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
        }

        vector<int> vis(n + 1, 0);
        queue<int> q;

        q.push(1);
        vis[1] = 1;

        int mnm = INT_MAX;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto it : adj[node]) {
                int cnode = it.first;
                int d = it.second;
                // yaha dhyn se dkho i am updting the weight but not pushing it in queue only pushing it in when its not vis 
                // so this is how 1st cse is solved even withpushing visiting the edge between 2-4 node i can get the dist atleast

                mnm = min(mnm, d);

                if (!vis[cnode]) {
                    vis[cnode] = 1;
                    q.push(cnode);
                }
            }
        }

        return mnm;
    }
};