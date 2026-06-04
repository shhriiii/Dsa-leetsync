class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(1LL * m * k > n) return -1;
        int day =1;
        int low  =1 , high = *max_element(bloomDay.begin(),bloomDay.end());
        while(low<=high){

            int mid = low + (high-low)/2;
            int count =0;
            int ans =0;
            for(int i =0;i<n;i++){
                if(bloomDay[i]<=mid) count++;
                else {
                    ans+= (count/k);
                    count =0;

                }
            }
            ans += count / k;
            if(ans >=m){
                high= mid -1;
                day =mid;
            }
            else{
                low = mid+1;
            }
        }
        return day;


        
    }
};