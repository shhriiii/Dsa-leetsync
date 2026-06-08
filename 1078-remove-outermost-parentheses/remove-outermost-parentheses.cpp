class Solution {
public:
    string removeOuterParentheses(string s) {
        int n =s.length();
        bool found =false;
        stack<pair<char , int>> st;
        set<int> idx;
        string ans ="";
        for(int i =0;i<n;i++){
            if(st.empty()){
                st.push({s[i],i});
            }
            else if(st.top().first=='(' && s[i]==')'){
                if(st.size()==1){
                    idx.insert(st.top().second);
                    idx.insert(i);
                    st.pop();
                }
                else {
                    // ans += "()";
                    st.pop();
                }
            }
            else{
                st.push({s[i],i});
            }

        }
        for(int i =0;i<n;i++){
            if(idx.find(i)!=idx.end()) continue;
            else{
                ans+=s[i];
            }
            
        }
        return ans;

        
    }
};