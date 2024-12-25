class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;

        while (true) {
            int size = nums.size();
            if (size - 1 == i) {
                break;
            }

            int current = nums[i];
            int next = nums[i+1];
            
            if (current == next) {
                nums.erase(nums.begin()+i+1);
                continue;
            } else {
                i++;
            }
        }

        return nums.size();
    }
};