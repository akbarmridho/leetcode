class Solution {
public:
    string reverseWords(string s) {
        int ptr = s.length()-1;

        string result = "";

        while(ptr >= 0) {
            if (s[ptr] == ' ') {
                ptr--;
                continue;
            }

            int sptr = ptr;

            while (sptr >= 0) {
                if (s[sptr] != ' ') {
                    sptr--;
                } else {
                    break;
                }
            }

            cout << "sptr " << sptr << " ptr " << ptr << "\n";
            cout << s.substr(sptr+1, ptr+1) << "\n";

            result = result + s.substr(sptr+1, ptr+1) + " ";

            cout << result << "\n";

            ptr = sptr;
        }

        return result.substr(0, result.length()-1);
    }
};