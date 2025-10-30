class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        deque<int> st;
        vector<int> answer;
        for(int i = 0; i < asteroids.size(); i++) {
            bool destroyed = false;
            while(!st.empty() && !destroyed) {
                if(st.back() < 0 || asteroids[i] > 0) break;
                else {
                    if(st.back() > -asteroids[i]) destroyed = true;
                    else if(st.back() == -asteroids[i]) {
                        st.pop_back();
                        destroyed = true;
                    }
                    else {
                        st.pop_back();
                    }
                }
            }
            if(!destroyed) st.push_back(asteroids[i]);
        }

        while(!st.empty()) {
            answer.push_back(st.front());
            st.pop_front();
        }

        return answer;
    }
};