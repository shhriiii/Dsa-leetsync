class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // pop or chng in +ve and neg
        // push in - and +
        stack<int> st;
        int n = asteroids.size();
        for (int i = 0; i < n; i++) {
            if (st.empty() || (st.top() > 0 && asteroids[i] > 0) ||
                (st.top() < 0 && asteroids[i] > 0) ||
                (st.top() < 0 && asteroids[i] < 0)) {
                st.push(asteroids[i]);
            } else {
                while (st.size()>0 && abs(asteroids[i]) > st.top() && st.top() > 0) {
                    st.pop();
                }
                if (st.size()>0 && st.top() == abs(asteroids[i])) {
                    st.pop();
                } else if( st.size()>0 && st.top() > abs(asteroids[i])){
                    continue;
                    
                }
                else st.push(asteroids[i]);
            }
        }
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};