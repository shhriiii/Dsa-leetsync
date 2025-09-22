class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq(101,0);
        int n = nums.size();
        for(int i=0;i<n;i++){
            freq[nums[i]]++;

        }
        int mxm = *max_element(freq.begin(),freq.end());
        int count=0;
        
        for(int i=0;i<101;i++){
            if(freq[i]==mxm) count+=freq[i];
        }
        return count;
        
    }
};