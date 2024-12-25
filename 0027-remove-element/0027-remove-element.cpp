class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int j = nums.size() - 1;

        while (i != j) {
            if (nums[i] == val) {
                if (nums[j] != val) {
                    int tmp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = tmp;
                } else {
                    j--;
                }
            } else {
                i++;
            }
        }

        int result = 0;

        int k = 0;

        while (k < nums.size()) {
            if (nums[k] != val) {
                result++;
                k++;
            } else {
                break;
            }
        }

        return result;
    }
};