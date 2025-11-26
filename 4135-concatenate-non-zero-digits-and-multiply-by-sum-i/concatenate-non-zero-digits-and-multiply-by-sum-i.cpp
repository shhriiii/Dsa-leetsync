class Solution {
public:
    long long sumAndMultiply(int n) {
        string s;
        long long sum =0;
        if(n==0) return 0;
        while(n>0){
            int ld = n%10;
            n/=10;
            sum+=ld;
            if(ld==0) continue;
            s.push_back(ld+'0');
        }
        reverse(s.begin(),s.end());
        int z = stoi(s);
        return z*sum;

        
    }
};
