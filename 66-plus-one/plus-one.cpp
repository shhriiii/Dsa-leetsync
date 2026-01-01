class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        string s = "";
        int n = digits.size();

        // digits -> string (FIXED)
        for (int i = 0; i < n; i++) {
            s += (digits[i] + '0');
        }

        int carry = 1;
        for (int i = s.size() - 1; i >= 0; i--) {
            int d = (s[i] - '0') + carry;
            s[i] = (d % 10) + '0';
            carry = d / 10;
            if (carry == 0) break;
        }

        if (carry) s = '1' + s;

        vector<int> ans;
        for (char c : s) {
            ans.push_back(c - '0');
        }

        return ans;
    }
};
