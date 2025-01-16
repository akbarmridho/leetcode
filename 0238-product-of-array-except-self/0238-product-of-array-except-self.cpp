class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int* prefixmul = new int[nums.size()];
        int* suffixmul = new int[nums.size()];

        int currentVal;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                currentVal = nums[i];
            } else {
                currentVal *= nums[i];
            }

            prefixmul[i] = currentVal;
        }

        for (int i = nums.size() - 1; i >= 0; i--) {
            if (i == nums.size() - 1) {
                currentVal = nums[i];
            } else {
                currentVal *= nums[i];
            }

            suffixmul[i] = currentVal;
        }

        for (int i = 0; i < nums.size(); i++) {
            int leftIdx = i - 1;
            int rightIdx = i + 1;

            int value = 1;

            if (leftIdx >= 0) {
                value *= prefixmul[leftIdx];
            }

            if (rightIdx <= nums.size() - 1) {
                value *= suffixmul[rightIdx];
            }

            nums[i] = value;
        }

        return nums;
    }
};