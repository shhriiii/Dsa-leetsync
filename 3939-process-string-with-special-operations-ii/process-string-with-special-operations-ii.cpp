#define ll long long
class Solution {
public:
    char processStr(string s, long long k) {
        ll len =0;
        int n = s.length();
        for(int i =0;i<n;i++){
            if(s[i]>='a' && s[i]<='z'){
                len++;
            }
            else if(s[i]=='#'){
                len*=2;
            }
            else if(s[i]=='*' && len>0){
                len--;
            }
            else{
                continue;
            }

        }
        cout<<len<<endl;
         if (k + 1 > len) {
            return '.';
        }
        
        for(int i =n-1;i>=0;i--){
            if(s[i]=='*'){
                len++;

            }
            else if(s[i]=='#'){
                len = len/2;
                if(k-len>=0){
                    k=k-len; //basically k = k-originalLen/2 but Len is alrdy len/2 -> k-len
                }

            }
            else if(s[i]=='%'){
                k=len-k-1;

            }
            else{
                len--;

            }
            if(k==len){
                cout<<i<<endl;
                return s[i];
            }
        }
        return '.';

        
    }
};