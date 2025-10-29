class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLength = -1, flipped = 0, left = 0, right = 0;
        while(right < nums.size()) {
            if(nums[right]) right++;
            else {
                flipped ++;
                right ++;
            }
            while(flipped > k) {
                if(!nums[left++]) flipped--;
            }
            maxLength = max(maxLength, right - left);
        }
        return maxLength;
    }
};