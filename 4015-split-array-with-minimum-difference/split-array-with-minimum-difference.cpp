#define ll long long
class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<ll> pref(n), suff(n);
        vector<bool> inc(n), dec(n);

        pref[0] = nums[0];
        for (int i = 1; i < n; i++) pref[i] = pref[i-1] + nums[i];

  
        suff[n-1] = nums[n-1];
        for (int i = n-2; i >= 0; i--) suff[i] = suff[i+1] + nums[i];

     
        inc[0] = true;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i-1] && inc[i-1]) inc[i] = true;
            else inc[i] = false;
        }

        dec[n-1] = true;
        for (int i = n-2; i >= 0; i--) {
            if (nums[i] > nums[i+1] && dec[i+1]) dec[i] = true;
            else dec[i] = false;
        }

        long long ans = LLONG_MAX;
        for (int i = 0; i < n-1; i++) {
            if (inc[i] && dec[i+1]) {
                ans = min(ans, llabs(pref[i] - suff[i+1]));
            }
        }

        return (ans == LLONG_MAX ? -1 : ans);
    }
};
