class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if (strs.empty()) return "";
        for (int idx = 0; idx < strs[0].size(); ++idx) {
            char compare = strs[0][idx];

            for (int i = 1; i < strs.size(); ++i) {
                // string does not match
                if (idx == strs[i].size() || strs[i][idx] != compare) {
                    return strs[0].substr(0, idx);
                }
            }

        }

        return strs[0];       
    }
};