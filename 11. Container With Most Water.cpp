class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxHeight = -1, maxArea = -1;
        for(int i = 0; i < height.size(); i++) maxHeight = max(maxHeight, height[i]);
        for(int h = maxHeight; h >= 0; h --) {
            int left = -1, right = height.size();
            do left ++; while(height[left] < h);
            do right --; while(height[right] < h);
            maxArea = max(maxArea, h * (right - left));
        }
        return maxArea;
    }
};