class Solution {
public:
    int isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    int maxVowels(string s, int k) {
        int current = 0, maxLength = -1;
        for(int i = 0; i < k; i ++) current += isVowel(s[i]);
        maxLength = current;
        for(int i = 1; i + k - 1 < s.length(); i++) {
            current = current - isVowel(s[i-1]) + isVowel(s[i+k-1]);
            maxLength = max(maxLength, current);
            if(maxLength == k) return k;
        }
        return maxLength;
    }
};