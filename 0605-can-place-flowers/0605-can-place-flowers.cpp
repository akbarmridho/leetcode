class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i = 0;

        while (i < flowerbed.size()) {
            if (flowerbed[i] == 0) {
                if (i + 1 < flowerbed.size()) {
                    if (flowerbed[i + 1] == 1) {
                        i += 3;
                    } else {
                        n--;
                        i += 2;
                    }
                } else {
                    if (flowerbed.size() == 1 || flowerbed[i-1] == 0) {
                        n--;
                    }

                    i+=2;
                }
            } else {
                i += 2;
            }
        }

        return n <= 0;
    }
};