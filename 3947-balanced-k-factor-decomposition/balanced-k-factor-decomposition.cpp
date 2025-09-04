class Solution {
public:
    vector<vector<int>> allPossible;

    void helper(int n, int k, int prod, vector<int>& curr, vector<int>& divisors) {
        if (k == 0) {
            if (prod == n) allPossible.push_back(curr);
            return;
        }
        for (int d : divisors) {
            if (1LL * prod * d > n) continue; // prune
            curr.push_back(d);
            helper(n, k - 1, prod * d, curr, divisors);
            curr.pop_back();
        }
    }

    vector<int> minDifference(int n, int k) {
        allPossible.clear();

        // Step 1: collect divisors
        vector<int> divisors;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                divisors.push_back(i);
                if (i != n / i) divisors.push_back(n / i);
            }
        }
        vector<int> curr;
        helper(n, k, 1, curr, divisors);

       
        int globalMin = INT_MAX;
        vector<int> ans;
        for (auto& seq : allPossible) {
            int mn = *min_element(seq.begin(), seq.end());
            int mx = *max_element(seq.begin(), seq.end());
            if (mx - mn < globalMin) {
                globalMin = mx - mn;
                ans = seq;
            }
        }
        return ans;
    }
};
