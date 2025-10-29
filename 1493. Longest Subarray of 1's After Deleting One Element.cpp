class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxLength = -1, left = 0, right = 0;
        bool deleted = false;
        while(right < nums.size()) {
            if(nums[right]) right++;
            else if(!deleted) {
                right++;
                deleted = true;
            }
            else {
                while(deleted) {
                    if(!nums[left++]) deleted = false;
                }
            }
            maxLength = max(maxLength, max(right - left - 1, 0));
        }
        return maxLength;
    }
};