class Solution {
public:
    string predictPartyVictory(string senate) {
        vector<char> senates;
        int radiant = 0;
        int dire = 0;

        for (char ch: senate) {
            senates.push_back(ch);

            if (ch == 'D') {
                dire++;
            } else {
                radiant++;
            }
        }

        int i = 0;

        while (dire != 0 && radiant != 0) {
            int toDelete = (i+1) % senates.size();

            while (senates[i] == senates[toDelete]) {
                toDelete = (toDelete+1) % senates.size();
            }

            if (senates[toDelete] == 'D') {
                dire--;
            } else {
                radiant--;
            }

            senates.erase(senates.begin()+toDelete);

            if (i > toDelete) {
                i--;
            }

            i = (i+1) % senates.size();
        }

        if (senates[0] == 'R') {
            return "Radiant";
        }

        return "Dire";
    }
};