class Solution {
    public long maximumHappinessSum(int[] h, int k) {
        Arrays.sort(h);
        int count =0;
        long ans =0;
        int n = h.length;
        for(int i=n-1;i>=0;i--){
            if(h[i]>count && k >0){
                ans += (h[i]-count);
                count++;
                k--;
            }
        }
        return ans;

        
    }
}