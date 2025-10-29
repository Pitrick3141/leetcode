class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxHeight = 0, current = 0;
        for(int i = 0; i < gain.size(); i++) {
            current += gain[i];
            maxHeight = max(maxHeight, current);
        }
        return maxHeight;
    }
};