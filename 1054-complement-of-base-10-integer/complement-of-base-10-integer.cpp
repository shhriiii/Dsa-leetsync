class Solution {
public:
    int bitwiseComplement(int n) {
         string s = "";
        int temp = n;
        if(n==0) return 1;
        
        while (temp > 0) {
            s = char((temp % 2) + '0') + s;
            temp /= 2;
        }
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') s[i] = '1';
            else s[i] = '0';
        }
        
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            ans = ans * 2 + (s[i] - '0');
        }
        
        return ans;
        
    }
};