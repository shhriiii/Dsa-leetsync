class Solution {
public:
    void dfs(int node , vector<vector<int>>& adj , vector<int>& vis){
        vis[node]=1;
        for(auto ngbr : adj[node]){
            if(!vis[ngbr]){
                dfs(ngbr , adj , vis);
            }
        }
        return;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int noOfedges = connections.size();
        if(n-1 >  noOfedges) return -1;
        //  no of component 
        vector<vector<int>> adj(n);
        for(int i =0 ; i<noOfedges;i++){
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis (n,0);
        int connectedComponent =0;
        for(int i =0;i<n;i++){
            if(!vis[i]){
                connectedComponent++;
                dfs(i,adj,vis);
            }

        }
        return connectedComponent-1;
        
    }
};