class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end() ,[&](vector<int>& a , vector<int>& b){
            if(a[0]==b[0]){
                return a[1]>b[1];
            }
            return a[0]<b[0];
        } );
            
        int count =0;
        int i =0 , j =i+1;
        while(j<n){
            int c = intervals[i][0];
            int d = intervals[i][1];
            while(j<n && c<= intervals[j][0] && d>=intervals[j][1]){
                j++;
                count++;
            }
            i=j;
            j++;
        }
        // int i =0 , j = 
        for(int i =0;i<n;i++){
            int a = intervals[i][0];
            int b = intervals[i][1];
            cout<<a<<" "<<b<<endl;

        }
        return n-count;
    }
};