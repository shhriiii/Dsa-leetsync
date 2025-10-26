
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (9 * num < sum) {
            return "";
        }
        
        string ans = "";

        while (num > 0) {
            int curr = min(9, sum);
            ans += to_string(curr);
            
         
            sum -= curr;
            num--;
        }
        

        return ans;
    }
};