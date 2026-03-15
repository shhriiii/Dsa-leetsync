class Solution {
public:
    vector<string> ans;

    void helper(int n, string &curr) {
        if (curr.length() == n) {
            ans.push_back(curr);
            return;
        }

        for (char ch : {'a', 'b', 'c'}) {
            if (curr.empty() || curr.back() != ch) {
                curr.push_back(ch);
                helper(n, curr);
                curr.pop_back();
            }
        }
    }

    string getHappyString(int n, int k) {
        string curr = "";
        helper(n, curr);

        if (k > ans.size()) return "";
        return ans[k - 1];   
    }
};