class Solution {
public:
    // void dfs(int node, int wt, vector<vector<int>>& adj, vector<int>& dist) {
    //     dist[node] = wt;

    //     for (auto neighbor : adj[node]) {

    //         if (dist[neighbor] == -1) {
    //             dfs(neighbor, wt + 1, adj, dist);
    //         }
    //     }
    //     return;
    // }
    // vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
    //     // ans.resize(n);
    //      vector<int> ans(n);

    //     vector<vector<int>> adj(n);
    //     for (auto it : edges) {
    //         adj[it[0]].push_back(it[1]);
    //         adj[it[1]].push_back(it[0]);
    //     }

    //     for (int i = 0; i < n; i++) {
    //         vector<int> dist(n, -1);
    //         dfs(i, 0, adj,dist);
    //         int sum = 0;
    //         for (int j = 0; j < n; j++){
    //             if(dist[j]!=-1) sum+=dist[j];
    //         }
    //         ans[i]=sum;

    //     }
    //     return ans;
    vector<int> count;
    vector<int> ans;
    vector<vector<int>> adj;
    int N;
    void dfs(int node , int par){
        for(auto ngbr : adj[node]){
            if(ngbr!=par){
                dfs(ngbr , node);
                count[node]+=count[ngbr];
                ans[0]
                += count[ngbr];
            }
        }
    }
    void dfs2(int node, int parent) {
        for (int neighbor : adj[node]) {
            if (neighbor != parent) {

                ans[neighbor] = ans[node] - count[neighbor] + (N - count[neighbor]);
                
  
                dfs2(neighbor, node);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        N = n;
        count.assign(n, 1);
        ans.assign(n, 0);
        adj.resize(n);
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        dfs(0,-1);
        dfs2(0,-1);
        return ans;
    }
};