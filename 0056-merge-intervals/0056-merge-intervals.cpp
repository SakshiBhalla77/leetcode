class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end());

        for(auto x : intervals)
        {
            if(ans.empty())
                ans.push_back(x);

            if(ans.back()[1] >= x[0])
                ans.back()[1] = max (ans.back()[1], x[1]);

            else
                ans.push_back(x);
        }

    return ans;
        
    }
};