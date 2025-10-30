class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int occurrence1[27], occurrence2[27];
        bool used[27];
        for(int i = 0; i < word1.length(); i++) occurrence1[word1[i] - 'a'] ++;
        for(int i = 0; i < word2.length(); i++) occurrence2[word2[i] - 'a'] ++;
        for(int i = 0; i < 27; i++) {
            if(!occurrence1[i]) {
                if(occurrence2[i]) return false;
                continue;
            }
            else if(!occurrence2[i]) return false;
            bool found = false;
            for(int j = 0; j < 27; j++) {
                if(occurrence2[j] == occurrence1[i] && !used[j]) {
                    found = true;
                    used[j] = true;
                    break;
                }
            }
            if(!found) return false;
        }
        return true;
    }
};