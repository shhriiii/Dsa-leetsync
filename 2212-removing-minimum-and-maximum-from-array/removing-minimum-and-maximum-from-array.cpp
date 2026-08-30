class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mnm = *min_element(nums.begin(),nums.end());
        int mxm = *max_element(nums.begin(),nums.end());
        if(n==1) return 1;
        int ans = INT_MAX;
        int count =0;
        for(int i =0;i<n;i++){
            count++;
            if(nums[i]==mnm || nums[i] == mxm){
                ans = count;
            }
            

        }
        ans = min(ans , count);
        count = 0;
        int temp =0;
        for(int i =n-1;i>=0;i--){
            count++;
            if(nums[i]==mnm || nums[i] == mxm){
                temp = count;
            }
            

        }
        ans = min(ans , temp);
        count = 0;
        for(int i =n-1;i>=0;i--){
            count++;
            if(nums[i]==mnm || nums[i] == mxm){
                // ans = count;
                break;
            }
            // count++;

        }
        int rcount = 0;
        for(int i =0;i<n;i++){
            rcount++;
            if(nums[i]==mnm || nums[i] == mxm){
                // ans = rcount;
                break;
            } 
        }
        ans = min(ans , rcount+count);
        return ans;

        
        
    }
};