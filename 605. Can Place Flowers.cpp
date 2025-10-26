class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int space = 1, flower = 0;
        for(auto it = flowerbed.begin(); it != flowerbed.end(); it++) {
            if(*it) {
                flower += (space - 1) / 2;
                space = 0;
            }
            else space ++;
        }
        flower += space / 2;

        return flower >= n;
    }
};