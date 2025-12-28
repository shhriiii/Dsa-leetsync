#define ll long long
class Solution {
public:
    long long maximumScore(vector<int>& nums) {

        ll n = nums.size();

        vector<ll> ps(n, 0);
        ps[0] = nums[0];

        for (ll i = 1; i < n; i++) {
            ps[i] = ps[i - 1] + nums[i];
        }

        vector<ll> suffix(n);
        ll mnm = LLONG_MAX;

        for (ll i = n - 1; i >= 0; i--) {
            mnm = min(mnm, (ll)nums[i]);   // ✅ FIX
            suffix[i] = mnm;
        }

        ll mxm = LLONG_MIN;
        for (ll i = 0; i < n - 1; i++) {
            mxm = max(mxm, ps[i] - suffix[i + 1]);
        }

        return mxm;
    }
};
