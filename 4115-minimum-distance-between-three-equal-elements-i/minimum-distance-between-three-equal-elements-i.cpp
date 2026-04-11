class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int dist=INT_MAX;
        int n = nums.size();
        for(int i =0;i<=n-3;i++){
            for(int j =i+1;j<=n-2;j++){
                for(int k =j+1;k<=n-1;k++){
                    if(nums[i]==nums[j] && nums[j]==nums[k]){
                        dist=min(abs(i-j)+abs(j-k)+abs(k-i),dist);
                    }
                }
            }

        }
        if(dist==INT_MAX) return -1;
        return dist;
        
    }
};