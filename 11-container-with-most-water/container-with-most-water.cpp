class Solution {
public:
    int maxArea(vector<int>& height) {
         int mxWt=0;
        int n=height.size();
        if(n==2) return min(height[0],height[1]);
        int left=0;
        int right=n-1;
        while(left < right){
            int currWt = min(height[left],height[right])*(right - left);
            mxWt = max(mxWt , currWt);
            if(height[left]>height[right]) right--;
            else left++;
        }
        return mxWt;
        
    }
};