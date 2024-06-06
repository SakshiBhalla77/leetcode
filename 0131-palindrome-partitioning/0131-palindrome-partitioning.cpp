class Solution {
public:
    void func(string s, int index, vector<vector<string>> &res,vector<string>&temp) 
    {
        if (index == s.size()) 
        {
            res.push_back(temp);
            return;
        }
        for (int i = index; i < s.size(); i++) 
        {
            if (isPalindrome(s, index, i)) 
            {
                temp.push_back(s.substr(index, i - index + 1));
                func(s, i + 1, res, temp);
                temp.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int start, int end) 
    {
        while (start <= end) 
        {
            if (s[start++] != s[end--])
            // {
                return false;
                //start++;
                //end--;
           // }
            
        }
        return true;
    }

    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> res;
        vector<string> temp;
        func(s, 0, res, temp);
        return res;
    }
};