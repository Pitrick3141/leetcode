class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeros = 0, index = 0;
        for(auto it = nums.begin(); it != nums.end(); it++) {
            if(*it) nums[index++] = *it;
            else zeros++;
        }
        while(zeros--) nums[index++] = 0;
    }
};