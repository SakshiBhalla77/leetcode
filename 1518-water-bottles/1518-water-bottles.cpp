class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange)
    {

        int drink = 0;

        if(numBottles == numExchange)
        drink = numBottles+ 1;

        else if(numBottles < numExchange)
        drink = numBottles;


        else 
        {
            int var = numBottles/numExchange;
            drink = numBottles+ var + 1;
        }
        

        return drink;
        
    }
};