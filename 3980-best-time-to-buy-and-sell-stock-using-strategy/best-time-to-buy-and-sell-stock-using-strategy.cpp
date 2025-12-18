#define ll long long
class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
         ll n = prices.size();
        
        vector<ll> currProfit(n,0);
        currProfit[0]= prices[0]*strategy[0];
        for(ll i=1;i<n;i++){
            currProfit[i] = 1LL*prices[i]*strategy[i];
        }
        vector<ll> sum(n,0);
        sum[0]=prices[0];
        for(ll i=1;i<n;i++){
            sum[i]=sum[i-1]+prices[i];

        }
        vector<ll> suffix(n,0);
        suffix[n-1]=currProfit[n-1];
        for(ll i=n-2;i>=0;i--){
            suffix[i]= suffix[i+1] + currProfit[i];
        }
        vector<ll> prefix(n,0);
        prefix[0]=currProfit[0];
        for(ll i=1;i<n;i++){
            prefix[i]=currProfit[i]+prefix[i-1];

        }
        ll maxP = prefix[n-1];
        ll i =0;
        ll j = k-1;
        while(j<n){
            ll windowSum = sum[j]-sum[j-k/2];
            ll  leftSum =0;
            ll rightSum =0;
            if(i>=1){
                leftSum = prefix[i-1];
            }
            if(j<=n-2){
                rightSum = suffix[j+1];
            }
            maxP = max(maxP,windowSum + leftSum+rightSum);
            j++;
            i++;
        }
        return maxP;
        
    }
};

