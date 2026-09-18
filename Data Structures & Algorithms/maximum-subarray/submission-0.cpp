class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int runningTotal{};
        int highestSum = nums[0];

        for (int i = 0; i < nums.size(); ++i) {
            runningTotal = std::max(nums[i], runningTotal + nums[i]);
            highestSum = std::max(highestSum, runningTotal);
        }

        return highestSum;
    }
};
