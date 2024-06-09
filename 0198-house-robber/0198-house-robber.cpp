class Solution {
public:
int solveUsingRecursion(vector<int>&nums, int n){
    if(n < 0)
        return 0;
    if(n == 0)
    //ek hi ghar hai (n -> index of house)
        return nums[0];

    //include
    int include = solveUsingRecursion(nums, n-2) + nums[n];
    int exclude = solveUsingRecursion(nums, n-1) + 0;

    return max(include, exclude);

}


int recursion2(vector<int>&nums , int size,int i){
     
    if(size < 0)
        return 0;

    if(size == 0)
       return nums[0];

    if(i>size)
        return 0;

    int include = recursion2(nums, size, i+2) + nums[i];
    int exclude = recursion2(nums,size , i+1);

    return max(include, exclude);

}

int solveUsingMemoisation(vector<int>& nums, int n, vector<int>&dp){
    if(n < 0)
        return 0;
    if(n == 0)
        return nums[0];

    if(dp[n]!= -1)
        return dp[n];
    
    int include = solveUsingMemoisation(nums, n-2, dp) + nums[n];
    int exclude = solveUsingMemoisation(nums, n-1, dp) + 0;

    dp[n] = max(include, exclude);
    return dp[n];
}

//top down approach
int solveUsingTabulation(vector<int>& nums, int n){
    vector<int> dp(n+1, 0);
    dp[0] = nums[0];

    if(n>0)
    dp[1] = max(nums[0] , nums[1]);

    
    for(int i=1; i<=n; i++)
    {
        if(i-2 >=0)
        {
        int include = dp[i-2] + nums[i];
        int exclude = dp[i-1] + 0;

        dp[i] = max(include, exclude);
        } 
        
    }
    return dp[n];
}

int solveOptimisedSpace(vector<int>& nums, int n){
    vector<int> dp(n+1, 0);
    dp[0] = nums[0];

        int prev1 = nums[0];
        int prev2 = 0;
        int curr = 0;

    for(int i=1; i<=n; i++)
    {

        int temp = 0;
        if(i-2 >=0)
            temp = prev2;
        
        int include = temp + nums[i];
        int exclude = prev1 + 0;
        
        curr = max(include, exclude);
        prev2 = prev1;
        prev1 = curr;
        
        
    }
    return prev1;
}

    int rob(vector<int>& nums) {
    int n = nums.size()-1;
    //return recursion(nums, n, 0);

    // vector<int> dp(n+1, -1);
    // return solveUsingMemoisation(nums, n, dp);

    //return solveUsingTabulation(nums, n);

    return solveOptimisedSpace(nums, n);

    }
};