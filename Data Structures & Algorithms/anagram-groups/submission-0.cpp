class Solution {
public:
    long long hash(string& str, int length) {
        long long hashNum{};

        for (auto c : str) {
            int h = c - 'a';
            hashNum += h*h;
            hashNum += h * (0.5 * h);
        }

        return hashNum % length;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<long long, vector<string>> hashValues{{}};

        for (auto str : strs) {
            long long h = hash(str, strs.size());

            hashValues[h].push_back(str);
        }

        vector<vector<string>> returnVector;

        for (auto& [hash, potentialAnagrams] : hashValues) {
            unordered_map<string, vector<string>> exactMatches;

            for (const string& str : potentialAnagrams) {
                string sortedStr = str;
                sort(sortedStr.begin(), sortedStr.end());

                exactMatches[sortedStr].push_back(str);
            }

            for (auto &[sortedKey, trueAnagrams] : exactMatches) {
                returnVector.push_back(trueAnagrams);
            }
        }

        return returnVector;
    }
};
