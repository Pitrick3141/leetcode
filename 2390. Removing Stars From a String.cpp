class Solution {
public:
    string removeStars(string s) {
        deque<char> st;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] != '*') st.push_back(s[i]);
            else st.pop_back();
        }
        string answer;
        while(!st.empty()) {
            answer += st.front();
            st.pop_front();
        }
        return answer;
    }
};