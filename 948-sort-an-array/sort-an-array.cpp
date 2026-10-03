class Solution {
public:
    void merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> temp;

        int i = low;
        int j = mid + 1;

        // Compare elements from both halves
        while (i <= mid && j <= high) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i]);
                i++;
            } else {
                temp.push_back(arr[j]);
                j++;
            }
        }

        // Remaining elements of left half
        while (i <= mid) {
            temp.push_back(arr[i]);
            i++;
        }

        // Remaining elements of right half
        while (j <= high) {
            temp.push_back(arr[j]);
            j++;
        }

        // Copy back into original array
        for (int k = low; k <= high; k++) {
            arr[k] = temp[k - low];
        }
    }
    void mergeSort(vector<int>& nums, int low, int high) {
        if(low>=high) return;
        int mid = low + (high - low) / 2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);
        merge(nums, low, mid, high);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums, 0, n - 1);
        return nums;
    }
};