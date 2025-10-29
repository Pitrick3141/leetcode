class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sumLeft = 0, sumRight = 0;
        for(int i = 0; i < nums.size(); i++) sumRight += nums[i];
        for(int i = 0; i < nums.size(); i++) {
            if(i) sumLeft += nums[i - 1];
            sumRight -= nums[i];
            if(sumLeft == sumRight) return i;
        }
        return -1;
    }
};