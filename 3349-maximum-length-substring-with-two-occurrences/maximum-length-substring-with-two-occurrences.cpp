class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        map<char , int> freq;
        int i =0,j=0;
        int maxLen =0;
        while(j<n){
            freq[s[j]]++;
            while(freq[s[j]]>2){
                freq[s[i]]--;
                i++;
            }
            maxLen = max(maxLen,j-i+1);
            j++;

        }
        return maxLen;
        
    }
};