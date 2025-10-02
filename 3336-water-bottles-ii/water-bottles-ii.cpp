class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int empty=0;
        int drink =0;
        while(true){
            drink+=numBottles;
            empty+=numBottles;
            numBottles=0;
            while(empty>=numExchange){
                empty-=numExchange;
                numExchange++;
                numBottles++;

            }
            if(numBottles==0 && numExchange > empty ) break;
        }
        return drink;
        
    }
};