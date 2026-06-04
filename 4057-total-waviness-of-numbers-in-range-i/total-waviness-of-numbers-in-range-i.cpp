class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int count =0;
        for(int i =num1;i<=num2;i++){
            int x =i;
            if(i<=99) continue;
            int prev =x%10;
            x/=10;
            int curr = x%10;
            x/=10;
            int next = x%10;
            x/=10;
            if((curr>prev && curr>next) || (curr<prev && curr<next)) count++;
            while(x>0){
                prev = curr;
                curr=next;
                next=x%10;
                x/=10;
                if((curr>prev && curr>next) || (curr<prev && curr<next)) count++;
            }
            
        }
        return count;
        
    }
};