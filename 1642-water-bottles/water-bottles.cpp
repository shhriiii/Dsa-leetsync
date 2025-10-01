class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int fullbottle =  numBottles;
        int emptybottle = numBottles;
        while(emptybottle>=numExchange){
            int newbottle= emptybottle / numExchange;
            int remainingEmptyBottles = emptybottle % numExchange;
            fullbottle+=newbottle;
            emptybottle=newbottle+remainingEmptyBottles;
        }
        return fullbottle;
        
    }
};