class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string longestPrefix{""};

        int idx = 0;
        int smallestLength = std::numeric_limits<int>::max();

        for (string str : strs) {
            if (str.size() < smallestLength) smallestLength = str.size();
        }

        while (idx < smallestLength) {
            char compare = strs[0][idx];

            for (int i = 1; i < strs.size(); ++i) {
                // string does not match
                if (strs[i][idx] != compare) {
                    return longestPrefix;
                }
            }

            longestPrefix += compare;

            idx++;
        }

        return longestPrefix;        
    }
};