class Solution {
public:
int n;
vector<vector<vector<int>>> dp;
    int helper(int chance , int idx , int m , vector<int>& piles ){
        if(idx>=n) return 0;

        int res = (chance == 0 ? -1 : INT_MAX); 
        int stones =0;
        if(dp[chance][idx][m]!=-1) return dp[chance][idx][m];
        for(int x = 1;x<=min(2*m , n-idx);x++){
            stones += piles[idx+x-1];
            if(chance == 0){
                // alice
                res = max(res , stones + helper(1,idx+x,max(m,x),piles));
                


            }
            else {
                res = min(res , helper(0,idx+x,max(m,x),piles));

            }
        }
        return dp[chance][idx][m]=res;

    }
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        dp.resize(2, vector<vector<int>>(101, vector<int>(202, -1)));
        return helper(0,0,1,piles);
        
    }
};