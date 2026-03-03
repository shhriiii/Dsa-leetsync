class Solution {
public:
    char findKthBit(int n, int k) {
        string ans = "0";

        for (int i = 2; i <= n; i++) {

            string temp = ans + "1";

            string flipped = ans;
            for (int j = 0; j < flipped.size(); j++) {
                flipped[j] ^= 1; 
            }

            reverse(flipped.begin(), flipped.end());

            ans = temp + flipped;
        }

        return ans[k - 1];
    }
};