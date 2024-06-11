class Solution {
public:
    int solveUsingRecursion(vector<int>& coins , int amount){
        //base case
        if(amount == 0){
            return 0;
        }
        if(amount < 0){
            return INT_MAX;
        }

        int mini = INT_MAX;
        for(int i =0; i<coins.size(); i++){
            int ans = solveUsingRecursion(coins, amount- coins[i]);
            if(ans!= INT_MAX){
                mini = min(mini, ans+1);
            }

        }
        return mini;
    }

    int solveTab(vector<int>& coins, int amount)
    {
        // Step 1: 
        vector<int> dp(amount+1, INT_MAX);

        // base case dekho 

        dp[0] =0;

        for(int target =1; target <= amount ; target++)
        {

            int mini = INT_MAX;

            for(int i=0; i< coins.size(); i++)
            {
                if(target - coins[i] >=0)
                {
                    int ans = dp[target - coins[i]];
                    if(ans != INT_MAX)
                    {
                        mini = min(mini, ans+1);
                    }
                }
            }
            dp[target] = mini;
        }
        return dp[amount];
    }


   


    
    int coinChange(vector<int>& coins, int amount) {
        // int ans = solveUsingRecursion(coins, amount);
        // if(ans == INT_MAX)
        // return -1;
        // else
        // return ans;
        // vector<int> dp(amount+1 , -1);
        // int ans = solveMem(coins, amount , dp);
        
    int ans = solveTab(coins , amount);
    if(ans== INT_MAX)
            return -1;
        else 
            return ans;

           

    }
};