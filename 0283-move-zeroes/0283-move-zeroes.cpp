class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int* tmp = (int *) malloc(sizeof(int)*nums.size());

        memset(tmp, 0, sizeof(int)*nums.size());

        int ptr = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                tmp[ptr] = nums[i];
                ptr++;
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            nums[i] = tmp[i];
        }
    }
};