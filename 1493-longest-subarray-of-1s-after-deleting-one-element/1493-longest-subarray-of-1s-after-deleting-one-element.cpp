class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int longest = 0;

        bool allone = true;

        for (auto num: nums) {
            if (num == 0) {
                allone = false;
                break;
            }
        }

        if (allone) {
            return nums.size() - 1;
        }

        for (int i = 0; i < nums.size(); i++) {
            // cout << "ival " << i << " ";
            if (nums[i] != 0) {
                continue;
            }

            int count = 0;
            // count leftmost
            if (i > 0) {
                int a = i - 1;

                while (a >= 0 && nums[a] == 1) {
                    a--;
                }

                count += i - a - 1;
                // cout << "left " << a;
                // cout << " left count " << i - a - 1;
            }

            if (i <= nums.size() - 1) {
                int b = i + 1;

                while (b <= nums.size() - 1 && nums[b] == 1) {
                    b++;
                }

                count += b - i - 1;
                // cout << " right " << b;
                // cout << " right count " << b - i - 1;
            }

            // cout << " count " << count << "\n";

            if (count > longest) {
                longest = count;
            }
        }

        return longest;
    }
};