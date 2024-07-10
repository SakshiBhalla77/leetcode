class Solution {
public:
    int minOperations(vector<string>& logs) 
    {
        int ans=0;
        for(auto&ch: logs)
        {
            if(ch == "../")
            {
                if(ans > 0) 
                ans--;
            }
            else if(ch != "./")
                ans++;

        }
        return ans;
    }
};