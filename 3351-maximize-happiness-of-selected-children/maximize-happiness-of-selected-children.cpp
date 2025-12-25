class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(),happiness.rend());
        int count =0;
        long long ans =0;
        int n = happiness.size();
        for(int i =0;i<n;i++){
            if(happiness[i]> count && k>0){
                ans += (happiness[i]-count);
                k--;
                count++;
            }
        }
        return ans;
        
    }
};