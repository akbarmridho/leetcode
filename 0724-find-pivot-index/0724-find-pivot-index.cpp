class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftsum = 0;
        int rightsum = 0;

        for (int i = 1; i < nums.size(); i++) {
            rightsum += nums[i];
        }

        if (leftsum == rightsum) {
            return 0;
        }

        int index = 0;

        for (int i = 0; i < nums.size()-1; i++) {
            index++;
            
            leftsum += nums[index-1];
            rightsum -= nums[index];
            
            if (leftsum == rightsum) {
                return index;
            }
        }

        return -1;
    }
};