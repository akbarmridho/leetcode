class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> q1;
        priority_queue<int, vector<int>, greater<int>> q2;

        int q1len = min((int)costs.size(), candidates);
        
        for (int i = 0; i < q1len; i++) {
            q1.push(costs[i]);
        }

        costs.erase(costs.begin(), costs.begin()+q1len);

        int csize = costs.size();
        int q2len = min(csize, candidates);
        
        for (int i = 0; i < q2len; i++) {
            q2.push(costs[csize - i - 1]);
        }

        costs.erase(costs.end() - q2len, costs.end());

        int totalCost = 0;

        for (int i = 0; i < k; i++) {
            int changeState = 0;

            if (!q1.empty() && !q2.empty()) {
                int q1val = q1.top();
                int q2val = q2.top();

                if (q1val <= q2val) {
                    totalCost += q1val;
                    q1.pop();
                    changeState = 1;
                } else {
                    totalCost += q2val;
                    q2.pop();
                    changeState = 2;
                }
            } else if (!q1.empty()) {
                totalCost += q1.top();
                q1.pop();
                changeState = 1;
            } else if (!q2.empty()) {
                totalCost += q2.top();
                q2.pop();
                changeState = 1;
            } else {
                break;
            }

            if (costs.size() > 0) {
                if (changeState == 1) {
                    // add remaining leftmost
                    q1.push(costs[0]);
                    costs.erase(costs.begin());
                } else if (changeState == 2) {
                    // add remaining rightmost
                    q2.push(*costs.rbegin());
                    costs.erase(costs.end()-1);
                }
            }
        }

        return totalCost;
    }
};