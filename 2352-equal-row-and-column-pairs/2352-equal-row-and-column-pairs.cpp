

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_multiset<string> rowmap;
        unordered_multiset<string> colmap;

        // iterate 
        for (int i = 0; i < grid.size(); i++) {
            string row = "";
            string col = "";

            for (int j = 0; j < grid.size(); j++) {
                row += std::to_string(grid[i][j]) + ".";
                col += std::to_string(grid[j][i]) + ".";
            }

            rowmap.insert(row);
            colmap.insert(col);
        }

        int counter = 0;

        for (auto row: rowmap) {
            counter += colmap.count(row);
        }

        return counter;
    }
};