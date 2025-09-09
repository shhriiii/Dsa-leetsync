class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        vector<int> freq(26, 0);

        bool allA = true;
        for(char c : s){
            if(c!='a'){
                allA = false;
                break;
            }
        }


        for (char c : s) freq[c - 'a']++;

        int count = 0;
        for (int i = 1; i < 26; i++) {
            if (freq[i] > 0) {
                int j = i;
                int currFreq = freq[i];
                freq[i] = 0;
                while (j <= 24 && freq[j] == 0) {
                    j++;
                }
                freq[j] += currFreq;
                count += (j - i);
            }
        }
        if(allA) return 0;
        return count + 1;
    }
};
