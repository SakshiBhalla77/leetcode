class Solution {
public:
 const int MOD = 1e9 +7;
  int solve(int ind, int target, vector<int>&nums, vector<vector<int>> &dp)
  {
      
        if(ind == 0)
        {
            if(target == 0 && nums[0] == 0) return 2;
            if(target == 0 || target == nums[0]) return 1;
        return 0;
        }

        if(dp[ind][target] != -1) return dp[ind][target];
        int notTake = solve(ind-1, target,nums,dp);
        int take = 0;
        if(nums[ind] <= target) take = solve(ind-1, target-nums[ind],nums, dp);
        
        return dp[ind][target] = (notTake + take)%MOD;
  }
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        //whose sum is total is equal to  (total - D) /2
        int totSum = 0;
        for(auto i : arr) 
        totSum += i;
        
        if(totSum -d < 0 || ( totSum-d)%2) return 0;
        int target = (totSum-d)/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return solve(n-1, target,arr,dp);
        
    }

    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int n = nums.size();
        return countPartitions(n, target , nums);

    }
};