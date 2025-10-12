class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int maxLen =0;
        for(int i =0;i<n;i++){
            vector<int> freq(26,0);
            
            for(int j=i;j<n;j++){
                freq[s[j]-'a']++;
                bool same =true;
                int mxm = *max_element(freq.begin(),freq.end());
                int count =0;
                for(int k = 0;k <26;k++){
                    if(freq[k]==0) continue;
                    if(freq[k]!=mxm){
                        same=false;
                        break;
                    }
                    else count+=freq[k];

                }
                if(same)maxLen = max(maxLen,count);
            }
            
        }
        return maxLen;
        
    }
};