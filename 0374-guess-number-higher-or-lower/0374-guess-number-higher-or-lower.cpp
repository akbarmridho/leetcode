/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        uint32_t low = 0;
        uint32_t high = n;

        while (true) {
            if (low == high) {
                return (int) low;
            }

            uint32_t guessValue;

            if ((high-low) % 2 == 1) {
                guessValue = low + (high-low + 1) / 2;
            } else {
                guessValue = low + (high-low) / 2;
            }

            uint32_t res = guess(guessValue);

            if (res == 0) {
                return (int) guessValue;
            } else if (res == 1) {
                low = guessValue;
            } else if (res == -1) {
                high = guessValue;
            }
        }

        return 0;
    }
};