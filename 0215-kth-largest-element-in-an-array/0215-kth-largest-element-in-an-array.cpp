class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() -  k;
        int lo = 0;
        int hi = nums.size() - 1;

        while (lo < hi) {
            int j = partition(nums, lo, hi);

            if (j < k) {
                lo = j + 1;
            } else if (j > k) {
                hi = j - 1;
            } else {
                break;
            }
        }

        return nums[k];
    }

    void swap(vector<int>& a, int i, int j) {
        int tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }

    int partition(vector<int>& nums, int lo, int hi) {
        int i = lo;
        int j = hi + 1;

        while (true) {
            while(i < hi && nums[++i] < nums[lo]);
            while(j > lo && nums[lo] < nums[--j]);

            if (i >= j) {
                break;
            }

            swap(nums, i, j);
        }

        swap(nums, lo, j);
        return j;
    }
};