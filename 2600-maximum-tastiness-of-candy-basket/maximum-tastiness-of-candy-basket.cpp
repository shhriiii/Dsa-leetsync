class Solution {
public:
    bool isPoss(int mid, int k, vector<int> &stalls) {
        int last = stalls[0];
        k--; 
        for (int i = 1; i < stalls.size(); i++) {
            if (stalls[i] - last >= mid) {
                k--;
                last = stalls[i];
            }
            if (k == 0) return true;
        }
        return false;
    }
    int maximumTastiness(vector<int>& price, int k) {
                sort(price.begin(), price.end());
        int n = price.size();
        int low = 1;
        int high = price[n - 1] - price[0];
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPoss(mid, k, price)) {
                ans = mid;       
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;

        
    }
};