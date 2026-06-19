class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi=INT_MIN;
        int n = gain.size();
        int prev =0;
        maxi= max(maxi,prev);
        for(int i =0;i<n;i++){
            // if(i==0) continue;
            int newH=prev+gain[i];
            maxi=max(newH,maxi);
            prev=newH;


        }
        return maxi;
        
    }
};