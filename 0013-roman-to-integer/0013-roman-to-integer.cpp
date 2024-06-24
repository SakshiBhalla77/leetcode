class Solution {
public:
    int romanToInt(string s) 
    {
        int ans = 0;
        int n = s.size();
        if (n == 0) return 0;

        map<char, int> mp = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}

        }; 
        if(n == 1) return (mp[s[0]]);

        ans += mp[s[n-1]];
        
        for(int i = n-2; i>=0; i--)
        {
             char ch = s[i];
             if(mp[ch] < mp[s[i +1]]) 
                ans -= mp[ch];
             else 
             ans += mp[ch];
        }
        return ans;
    }
};