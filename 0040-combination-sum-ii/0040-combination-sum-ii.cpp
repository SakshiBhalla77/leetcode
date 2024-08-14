class Solution {
public:
void solve(vector<int>& candidates, int target, vector<vector<int>> ans, vector<int>&temp,int ans, int index )
{
    if(index >= candidates.size()) return;

    if(target == sum){
        ans.push_back(temp);
        return;
    }
    if(sum>target) return;

    for(int i = index ; i< candidates.size(),i++)
    {
        if(i!=index && candidates[i]== candidates[i-1]) continue;
        
    }


}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
    }
};