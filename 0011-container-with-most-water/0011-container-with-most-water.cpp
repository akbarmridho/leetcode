class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int size = (j-i)*min(height[i], height[j]);

        while (i != j) {
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }

            int currentSize = (j-i)*min(height[i], height[j]);

            if (currentSize > size) {
                size = currentSize;
            }
        }

        return size;
    }
};