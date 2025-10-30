class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        vector<int> inc(n);
        inc[0]=target[0];
        int mnm = inc[0];
        int ans =0;

        for(int i =1;i<n;i++){
            if(target[i]<target[i-1]){
                ans+= (target[i-1]-target[i]);

            }
        }
        return ans+target[n-1];
        
        
    }
};




// 3 1 1 1 2 3
// 1 1 1 1 1 1
// 1 1 1 1 2 2
// 2 1 1 1 2 2
// 3 1 1 1 2 2
// 3 1 1 1 2 3

// 5 4 2 1 2 5
// 0 0 0 0 0 0
// 1 1 1 1 1 1 
// 2 2 2 1 2 2
// 3 3 2 1 2 3