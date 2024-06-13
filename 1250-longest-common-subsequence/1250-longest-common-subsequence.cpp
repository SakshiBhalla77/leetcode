// class Solution {
// public:
// int solve(int index1, int index2, string text1, string text2, vector<vector<int>>& dp )
// {
//     //BASE CASE
//     if(index1 < 0 || index2 < 0)
//     return 0;

//     if(dp[index1][index2] != -1)
//     return dp[index1][index2];

//     if(text1[index1] == text2[index2])
//     return 1 + solve(index1-1, index2-1, text1,  text2,dp);


// return  dp[index1][index2]= max(solve(index1 - 1, index2, text1,  text2,dp), solve(index1, index2 -1, text1,  text2, dp));

// }
//     int longestCommonSubsequence(string text1, string text2) 
//     { 
//         int index1 = text1.length();
//         int index2 = text2.length();
//         vector<vector<int>> dp(index1 , vector<int>(index2 , -1));
        
//         return solve(index1-1, index2-1, text1,  text2,dp );

//     }
// };

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        int len1 = text1.length();
        int len2 = text2.length();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        
        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[len1][len2];
    }
};