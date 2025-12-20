class Solution {
    public int minDeletionSize(String[] strs) {
        int n = strs.length;
        int count =0;
        int m = strs[0].length();
        for(int idx =0;idx<m;idx++){
            char c = strs[0].charAt(idx);
            for(int i =1;i<n;i++){
                if(c>strs[i].charAt(idx)){
                    count++;
                    break;
                }
                c = strs[i].charAt(idx);
            }
        }
        return count;
    }
}