#define ll long long
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        // return min({1LL*cost1*need1 + 1LL*cost2*need2 , 1LL*costBoth*max(need1,need2)});
        if(cost1+cost2 > costBoth){
            int diff = abs(need1-need2);
            int mnm = min(need1 , need2);
            ll ans = 1LL*costBoth*mnm;
            if(need1>=need2){
                ans += (1LL*diff*cost1);
            }
            else ans += (1LL*diff*cost2);
               return min({ans,1LL*cost1*need1 + 1LL*cost2*need2 , 1LL*costBoth*max(need1,need2)});
            


        }
        else{
            return min({1LL*cost1*need1 + 1LL*cost2*need2 , 1LL*costBoth*max(need1,need2)});

        }
        
    }
};