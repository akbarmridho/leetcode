class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() <= 2) {
            return false;
        }

        int* small = new int[nums.size()];
        int* large = new int[nums.size()];

        int s = nums[0];

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < s) {
                s = nums[i];
            }

            small[i] = s;
        }

        int l = nums[nums.size() - 1];

        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] > l) {
                l = nums[i];
            }

            large[i] = l;
        }

        bool found = false;

        for (int i = 1; i <= nums.size() - 2; i++) {
            if (nums[i] > small[i-1] && nums[i] < large[i+1]) {
                found = true;
                break;
            }
        }

        return found;
    }
};