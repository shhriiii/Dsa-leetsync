class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int helper(string &s , int i , int j){
        // base
        if(i>=j) return 0;
        int same = INT_MAX , notsame = INT_MAX ;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==s[j]){
            same = helper(s,i+1,j-1);
            

        }
        else{
            notsame = 1+min(helper(s,i+1,j),helper(s,i,j-1));
        }
        return dp[i][j]= min(same,notsame);
    }
    int minInsertions(string s) {
        n = s.length();
        dp.resize(n+1,vector<int>(n+1,-1));
        return helper(s , 0,n-1);
        
    }
};