class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int count =0;
        int m = strs[0].size();
        int idx =0;
        for(int idx =0 ;idx<m;idx++){
            char c = strs[0][idx];
            for(int i =1;i<n;i++){
                if(c>strs[i][idx]){
                    count++;
                    break;
                }
                c = strs[i][idx];

            }
        }
        return count;
        
    }
};