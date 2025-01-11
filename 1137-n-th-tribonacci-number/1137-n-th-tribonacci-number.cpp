#include <vector>

class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) {
            return 0;
        }

        if (n == 1 || n == 2) {
            return 1;
        }

        vector<int> trival(n+1, 0);

        trival[1] = 1;
        trival[2] = 1;

        for (int i = 3; i <= n; i++) {
            trival[i] = trival[i-1] + trival[i-2] + trival[i-3];
        }

        return trival[n];
    }
};