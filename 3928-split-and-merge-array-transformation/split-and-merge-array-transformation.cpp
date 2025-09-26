class Solution {
public:
    vector<vector<int>> gen(vector<int> a) {
    int n = a.size();
    vector<vector<int>> ans;

    // pick the subarray to cut
    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {

            // create the cut piece
            vector<int> cutpiece;
            for (int idx = l; idx <= r; idx++) {
                cutpiece.push_back(a[idx]);
            }

            // create the remaining array after cutting
            vector<int> vec;
            for (int i = 0; i < n; i++) {
                if (i < l || i > r) {
                    vec.push_back(a[i]);
                }
            }

            // insert the cut piece at every possible position
            for (int j = 0; j <= vec.size(); j++) {
                vector<int> fnal;

                // add the first j elements
                for (int k = 0; k < j; k++) fnal.push_back(vec[k]);

                // add the cut piece
                for (int x : cutpiece) fnal.push_back(x);

                // add the remaining elements
                for (int k = j; k < vec.size(); k++) fnal.push_back(vec[k]);

                // avoid adding the original array itself
                if (fnal != a) ans.push_back(fnal);
            }

        }
    }

    return ans;
}

    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int ans =0;
        queue<pair<vector<int> , int >> q;
        map<vector<int> , int> vis;
        q.push({nums1,0});
        while(!q.empty()){
            auto top = q.front();
            auto topvec = top.first; 
            q.pop();
            int ansval = top.second;
            vis[topvec]++;
            if(topvec==nums2) return ansval;
            for(auto it : gen(topvec)){
                if(!vis[it]){
                    q.push({it , ansval+1});
                    vis[it]++;
                }

            }
        }
        return 0;

        
    }
};