class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int occurrence[2010], res[1010];
        memset(occurrence, 0, sizeof(occurrence));
        memset(res, 0, sizeof(res));
        for(int i = 0; i < arr.size(); i++) {
            occurrence[arr[i] + 1000] ++;
        }
        for(int i = 0; i < 2010; i++) {
            if(occurrence[i]) res[occurrence[i]] ++;
            if(res[occurrence[i]] > 1) return false;
        }
        return true;
    }
};