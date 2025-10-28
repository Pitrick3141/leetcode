class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int maxSum = -1, current = 0;
        for(int i = 0; i < k; i++) current += nums[i];
        maxSum = current;
        for(int i = 1; i + k - 1 < nums.size(); i++) {
            current = current - nums[i-1] + nums[i+k-1];
            maxSum = max(maxSum, current);
        }
        return (1.0 * maxSum) / (1.0 * k);
    }
};