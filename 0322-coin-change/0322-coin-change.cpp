class Solution {
public:
//fun returns- min coins we require to form amount 
//take wale case me same index pe stand krna 
int solve(int index , vector<int>& coins, int amount, vector<vector<int>> &dp )
{
    //Base case 
    if(index == 0 )
    {
        if(amount % coins[0] == 0)
        return amount/coins[0];

        else return 1e9;
    }  
    if(dp[index][amount] != -1) return dp[index][amount];

    int notTake = 0 + solve(index-1, coins, amount, dp);

    int take = INT_MAX;
    if(coins[index] <= amount) 
    
    take = 1 + solve(index, coins , amount - coins[index], dp);

    return dp[index][amount] = min(take, notTake);

}


    int coinChange(vector<int>& coins, int amount) 
    {
        int n = coins.size();

       vector<vector<int>> dp (n, vector<int>(amount+1 , -1));
        int ans = solve(n-1 , coins,  amount, dp);
        if(ans >= 1e9) return -1;
        else return ans;
    }
};