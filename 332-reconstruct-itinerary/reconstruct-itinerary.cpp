class Solution {
public:
    vector<string> ans;
    void dfs(unordered_map<string , vector<string>>& adj, string u){
        while(!adj[u].empty()){
            string v = adj[u].back();
            adj[u].pop_back();
            dfs(adj,v);
        }
        ans.push_back(u);
        return;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string , vector<string>> adj;
        int n = tickets.size();
        for(int i =0;i<n;i++){
            string from = tickets[i][0];
            string to = tickets[i][1];
            adj[from].push_back(to);
        }
        ans.clear();
                for(auto & it : adj){
            sort(it.second.rbegin(),it.second.rend());
        }
        dfs(adj,"JFK");

        for(int i =0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        reverse(ans.begin(),ans.end());
        return ans;


        
    }
};