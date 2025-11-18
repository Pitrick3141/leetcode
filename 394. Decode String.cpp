class Solution {
public:
    string decodeString(string s) {
        stack<string> stringStack;
        stack<int> multiplierStack;
        int currentIndex = 0;
        string res = "";
        int multiplier = -1;
        while(currentIndex < s.length()) {
            if(s[currentIndex] >= '0' && s[currentIndex] <= '9') {
                if(multiplier == -1) {
                    multiplier = s[currentIndex] - '0';
                }
                else {
                    multiplier = multiplier * 10 + (s[currentIndex] - '0');
                }
            }
            else if(s[currentIndex] == '[') {
                // String before bracket
                stringStack.push(res);
                // Multiplier for the bracket
                multiplierStack.push(multiplier);
                res = "";
                multiplier = -1;
            }
            else if(s[currentIndex] == ']') {
                if(multiplier != -1) {
                    res += to_string(multiplier);
                }
                multiplier = multiplierStack.top();
                multiplierStack.pop();
                string newRes = stringStack.top();
                stringStack.pop();
                while(multiplier--) {
                    newRes += res;
                }
                res = newRes;
            }
            else {
                if(multiplier != -1) {
                    res += to_string(multiplier);
                }
                res += s[currentIndex];
                multiplier = -1;
            }
            currentIndex ++;
        }
        return res;
    }
};