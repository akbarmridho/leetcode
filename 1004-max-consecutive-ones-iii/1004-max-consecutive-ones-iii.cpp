class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int maxlen = 0;
        int nzero = 0;

        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] == 0) {
                nzero++;
            }

            while (nzero > k) {
                if (nums[left] == 0) {
                    nzero--;
                }
                left++;
            }

            int len = r - left + 1;

            if (len > maxlen) {
                maxlen = len;
            }
        }

        return maxlen;
    }
};