class Solution {
    public long maximumScore(int[] nums) {
        int n = nums.length;
        long[] ps = new long[n];
        ps[0]=nums[0];
        for(int i =1 ; i <n;i++){
            ps[i] = nums[i]+ps[i-1];
        }
        long suffix [] = new long[n];
        long mnm = Long.MAX_VALUE;
        for(int i =n-1;i>=0;i--){
            mnm =Math.min(nums[i],mnm);
            suffix[i]=mnm;
        }
        long ans = Long.MIN_VALUE;
        for(int i =0;i<n-1;i++){
            ans = Math.max(ans , ps[i]-suffix[i+1]);

        }
        return ans;
        
        
    }
}