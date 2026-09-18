class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int runningMax = 0, runningMin = 0;
        int maxMiddleSum = nums[0], minMiddleSum = nums[0];
        int arraySum = 0;

        for (int num : nums) {
            arraySum += num;

            runningMax = max(num, runningMax+num);
            maxMiddleSum = max(maxMiddleSum, runningMax);

            runningMin = min(num, runningMin + num);
            minMiddleSum = min(minMiddleSum, runningMin);
        }

        if (maxMiddleSum < 0) {
            return maxMiddleSum;
        }

        return max(maxMiddleSum, arraySum - minMiddleSum);
    }
};