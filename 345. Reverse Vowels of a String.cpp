class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    string reverseVowels(string s) {
        int left = -1, right = s.length();
        while(left < right) {
            do left ++; while(!isVowel(s[left]) && left < right);
            do right --; while(!isVowel(s[right]) && left < right);
            if(left < right) swap(s[left], s[right]);
        }
        return s;
    }
};