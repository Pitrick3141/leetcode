class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string mergedString;
        int index = 0, size1 = word1.length(), size2 = word2.length();
        while(index < size1 || index < size2) {
            if(index < size1) mergedString += word1[index];
            if(index < size2) mergedString += word2[index];
            index++;
        }
        return mergedString;
    }
};