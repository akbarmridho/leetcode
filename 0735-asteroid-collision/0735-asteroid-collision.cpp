#include <stack>
#include <vector>
#include <algorithm>

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> ss;

        int i = 0;

        while (i < asteroids.size()) {
            if (ss.empty()) {
                ss.push(asteroids[i++]);
                continue;
            }

            // check for collision
            if (asteroids[i] < 0 && ss.top() > 0) {
                // current are bigger
                if (asteroids[i]*-1 > ss.top()) {
                    ss.pop();
                } else if (asteroids[i]*-1 < ss.top()) {
                    i++;
                } else {
                    // equal
                    i++;
                    ss.pop();
                }
            } else {
                // same direction
                ss.push(asteroids[i++]);
            }
        }

        vector<int> result;

        while (!ss.empty()) {
            result.push_back(ss.top());
            ss.pop();
        }

        std::reverse(result.begin(), result.end());

        return result;
    }
};