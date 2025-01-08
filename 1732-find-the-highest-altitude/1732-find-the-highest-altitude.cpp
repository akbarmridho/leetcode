class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int result = 0;
        int* resarr = new int[gain.size()+1];
        memset(resarr, 0, sizeof(int)*(gain.size()+1));
        
        for (int i = 0; i < gain.size(); i++) {
            // x[i+1] - x[i] = g[i]
            resarr[i+1] = resarr[i] + gain[i];

            if (resarr[i+1] > result) {
                result = resarr[i+1];
            }
        }

        return result;
    }
};