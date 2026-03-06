class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.length();
        bool one = false;
        bool zero = false;
        for(int i =0;i<n;i++){
            if(s[i]=='1' && one==false){
                one=true;
            }
            else if(s[i]=='0' && one){
                zero=true;
            }
            else if(s[i]=='1' && zero) return false;
        }
        return true;
        
    }
};