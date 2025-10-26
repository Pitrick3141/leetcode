class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result;
        int maxCandy = -1;
        for(auto it = candies.begin(); it != candies.end(); it++) {
            if (*it > maxCandy) maxCandy = *it;
        }
        for(auto it = candies.begin(); it != candies.end(); it++) {
            result.push_back(*it + extraCandies >= maxCandy);
        }
        return result;
    }
};