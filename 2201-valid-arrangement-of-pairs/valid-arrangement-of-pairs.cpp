        //  outdegree[x] - indegree[x] ==1 -> starting node (euler path concept)
        // In a directed graph, an indegree is the number of edges entering a node, while an outdegree is the number of edges leaving it. For an Euler Path, every intermediate node must have equal indegree and outdegree because every time you enter that node, you must also leave it. The starting node has one extra outgoing edge since the journey begins there without first entering it, so outdegree = indegree + 1. The ending node has one extra incoming edge because the journey ends there without leaving it, so indegree = outdegree + 1. If the graph forms an Euler Circuit, the path starts and ends at the same node, meaning every node must have indegree = outdegree. These degree conditions help determine whether an Euler Path or Euler Circuit is possible and identify the correct starting and ending nodes
class Solution {
public:
    vector<int> euler;
    void dfs(int u , unordered_map<int, vector<int>>& adj){
        while(!adj[u].empty()){
            int v = adj[u].back();
            adj[u].pop_back();
            dfs(v,adj);
        }
        euler.push_back(u);
    }
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {

        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> indegree, outdegree;

        // Build adjacency list and calculate indegree/outdegree
        for (auto &p : pairs) {
            int u = p[0];
            int v = p[1];

            adj[u].push_back(v);
            outdegree[u]++;
            indegree[v]++;
        }

        // Assume first node as start (Euler Circuit case)
        int start = pairs[0][0];

       
        for (auto &[node, deg] : outdegree) {
            if (outdegree[node] == indegree[node] + 1) {
                start = node;
                break;
            }
        }

        // heirholzer algo
        euler.clear();
        dfs(start , adj);
        vector<vector<int>> ans;
        for(int i =euler.size()-1;i>=1;i--){
            ans.push_back({euler[i],euler[i-1]});
        }
        return ans;
        


    }
};