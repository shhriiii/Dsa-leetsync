class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int ele : asteroids) {

            if (st.empty() || ele > 0 || st.top() < 0) {
                st.push(ele);
            } 
            else {

                bool destroyed = false;

                while (!st.empty() && st.top() > 0) {
                    if (abs(st.top()) < abs(ele)) {
                        st.pop(); 
                        continue;
                    } 
                    else if (abs(st.top()) == abs(ele)) {
                        st.pop(); 
                        destroyed = true;
                    }
                    destroyed = true;
                    break;
                }

                if (!destroyed) st.push(ele);
            }
        }

        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            result[i] = st.top();
            st.pop();
        }
        return result;
    }
};
