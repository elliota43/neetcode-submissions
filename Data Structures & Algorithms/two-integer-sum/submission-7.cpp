class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> seen;

        for (int i{}; i < nums.size(); ++i) {
            int want = target - nums[i];

            if (seen.contains(want)) {
                return {seen[want], i};
            }

            seen[nums[i]] = i;
        }

        return {};
    }
};
