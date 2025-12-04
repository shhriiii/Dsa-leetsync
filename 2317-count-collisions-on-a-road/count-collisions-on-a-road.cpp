class Solution {
public:
    int countCollisions(string dir) {
        stack<char> st;
        int n = dir.size();
        int count = 0;
        st.push(dir[n - 1]);

        for (int i = n - 2; i >= 0; i--) {
            char curr = dir[i];
            if (curr == 'S') {
                while (!st.empty() && st.top() == 'L') {
                    count++;
                    st.pop();
                }
                st.push('S');
            } 
            else if (curr == 'L') {

                st.push('L');
            } 
            else { 
                if (!st.empty() && st.top() == 'L') {
                    count += 2;
                    st.pop(); 
                    while (!st.empty() && st.top() == 'L') {
                        count++;
                        st.pop();
                    }
                    st.push('S'); 
                } 
                else if (!st.empty() && st.top() == 'S') {
                    count++;
                    st.push('S'); 
                } 
                else {
                    st.push('R');
                }
            }
        }
        return count;
    }
};