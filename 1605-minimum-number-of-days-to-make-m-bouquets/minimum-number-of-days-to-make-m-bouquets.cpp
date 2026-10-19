class Solution {
public:
    bool isPossible(vector<int>& bloomDay, int m, int k, int mid) {
        int currDate = mid;
        int count = 0;
        int totalBouqet = 0;
        int n = bloomDay.size();
        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= currDate) {
                count++;
            } else {
                count = 0;
            }
            if (count == k) {
                totalBouqet++;
                count = 0;
            }
            if (totalBouqet == m) {
                return true;
            }
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(1LL * m * k > n) return -1;
            // return -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(bloomDay, m, k, mid)) {
                high = mid - 1;
                ans = mid;
                cout<<ans<<endl;
            } else
                low = mid + 1;
        }
     
        return ans;
    }
};