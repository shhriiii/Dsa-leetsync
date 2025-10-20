class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        set<string> st(bank.begin(),bank.end());
        vector<char> gene = {'A','C','G','T'};
        queue<pair<int,string>> q;
        q.push({0,startGene});
        while(!q.empty()){
            auto [ step , curr]=q.front();
            q.pop();
            if(curr==endGene) return step;
            string temp = curr;
            for(int i =0;i<temp.size();i++){
                char ch = temp[i];
                for(int j=0;j<4;j++){
                    temp[i]=gene[j];
                    if(st.count(temp)){
                        q.push({step+1,temp});
                        st.erase(temp); 
                    }
                    temp[i]=ch;
                }
            }
        }
        return -1;
        
    }
};