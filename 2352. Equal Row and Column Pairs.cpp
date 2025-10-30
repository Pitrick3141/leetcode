class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<string, int> occurrence;
        int answer = 0;
        for(int i = 0; i < grid.size(); i++) {
            string key = "";
            for(int j = 0; j < grid.size(); j++) key += "/" + to_string(grid[i][j]);
            if(occurrence.find(key) == occurrence.end()) occurrence[key] = 1;
            else occurrence[key] ++;
        }
        for(int i = 0; i < grid.size(); i++) {
            string key = "";
            for(int j = 0; j < grid.size(); j++) key += "/" + to_string(grid[j][i]);
            if(occurrence.find(key) != occurrence.end()) answer += occurrence[key];
        }
        return answer;
    }
};
