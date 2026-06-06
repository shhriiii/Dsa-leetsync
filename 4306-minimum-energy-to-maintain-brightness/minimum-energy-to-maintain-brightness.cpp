class Solution {
public:
    long long minEnergy(int n, int b, vector<vector<int>>& intervals) {
        int m = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> merged;
        merged.push_back(intervals[0]);
        for(int i =1;i<m;i++){
            int ps = merged.back()[0];
            int pe = merged.back()[1];

            int cs = intervals[i][0];
            int ce = intervals[i][1];
            if(pe>=cs){
                merged.back()[1] = max(pe,ce);
            }
            else merged.push_back({cs,ce});
        }
        int reqB = b/3;
        if(b%3>0) reqB++;
        long long total =0;
        for(int i =0;i<merged.size();i++){
            long long cint = merged[i][1]-merged[i][0] + 1;
            total += 1LL*reqB*cint;
        }
        // for(int i =0;i<merged.size();i++){
        //     cout<< merged[i][1]<<" ";
        //     cout<<merged[i][0];
        //     // total += 1LL*reqB*cint;
        // }
        
        return total;
        

        
    }
};