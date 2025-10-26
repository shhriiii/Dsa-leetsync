#define ll long long
class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        ll count = 0;
        int n = nums1.size();
        for (int i = 0; i < n; i++) {
            ll diff = abs(nums2[i] - nums1[i]);
            count += diff;
        }
        int last = nums2[n];
        bool found = false;
        for (int i = 0; i < n; i++) {
            int mnm = min(nums1[i], nums2[i]);
            int mxm = max(nums1[i], nums2[i]);
            if (last >= mnm && last <= mxm) {
                found = true;
                break;
            }
        }
        count++;
        cout<<"count bfr append "<<count<<endl;
        if (found) {
            return count;
        }
        int mDiff = INT_MAX;
        for (int i = 0; i < n; i++) {
            int diff = abs(nums1[i] - last);
            mDiff = min(mDiff, diff);
        }
        cout<<"mdiff bf "<<mDiff<<endl;
        for (int i = 0; i < n; i++) {
            int diff = abs(nums2[i] - nums1[i]);
            if(nums2[i]>=nums1[i]){
                nums1[i]+=diff;
            }
            else{
                nums1[i]-=diff;
            }
        }



        // mDiff = INT_MAX;
        for (int i = 0; i < n; i++) {
            int diff = abs(nums1[i] - last);
            mDiff = min(mDiff, diff);
        }


        count += mDiff;
        cout<<"mdiff aff "<<mDiff<<endl;
        for(int i =0;i<n;i++){
            cout<<nums1[i]<<" ";
        }
        cout<<endl;
        return count;
    }
};