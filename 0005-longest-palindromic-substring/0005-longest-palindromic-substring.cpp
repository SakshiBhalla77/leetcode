class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& dp, string &s) {
        if (i==j || abs(i-j) == 1) {
            if (s[i] == s[j]) {
                return abs(i-j) + 1;
            }
            return 0;
        }
        if (dp[i][j]!=-1) {
            return dp[i][j];
        }
        int p = solve(i+1, j-1, dp, s);
        if (p) {
            if (s[i] == s[j]) {
                p = p + 2;
            } else {
                p = 0;
            }
        }
        
        dp[i][j] = p;
        return p;
    }
    string longestPalindrome(string s) {
        vector<vector<int>> v(s.size(), vector<int> (s.size(), -1));
        int largest = 0;
        int a = 0, b = 0;
        for(int i=0;i<s.size();i++) {
            for(int j=i;j<s.size();j++) {
                int t = solve(i, j, v, s);
                if (t>largest) {
                    largest = t;
                    a = i;
                    b = j;
                }
            }
        }
        
        return s.substr(a, b-a+1);
    }
};


        