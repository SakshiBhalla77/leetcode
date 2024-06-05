class Solution {
public:
    void solve(vector<int>& candidates, int target, vector<vector<int>>& ans,
               vector<int>& temp, int index, int sum) {
        
        if (sum == target) {
            ans.push_back(temp);
            return;
        }

        if (index >= candidates.size())
            return;


        if (sum > target)
            return;

        for (int i = index; i < candidates.size(); i++) 
        {
            if (i != index && candidates[i] == candidates[i - 1])
                continue;
        
        temp.push_back(candidates[i]);
        solve(candidates, target, ans, temp, i + 1, sum + candidates[i]);
        temp.pop_back();
        //solve(candidates, target, ans, temp, index + 1, sum);

        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        int sum = 0;
        sort(candidates.begin(), candidates.end());
        vector<int> temp;

        solve(candidates, target, ans, temp, 0, sum);
        return ans;
    }
};