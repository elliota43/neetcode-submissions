class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int, int> seen{};

        for (int i{}; i < nums.size(); ++i) {
            int want = target - nums.at(i);

            if (seen.contains(want)) {
                return {seen[want], i};
            }

            seen[nums.at(i)] = i;
        }
    }
};
