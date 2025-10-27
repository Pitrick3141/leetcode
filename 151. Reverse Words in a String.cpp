class Solution {
public:
    string reverseWords(string s) {
        vector<int> wordBeginIndex;
        string reversed;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] != ' ') {
                wordBeginIndex.push_back(i);
                do i++; while(i < s.length() && s[i] != ' ');
            }
        }
        for(int i = wordBeginIndex.size() - 1; i >= 0; i --) {
            int index = wordBeginIndex[i];
            while(index < s.length() && s[index] != ' ') reversed += s[index++];
            if(i > 0) reversed += ' ';
        }
        return reversed;
    }
};