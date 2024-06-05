class Solution {
public:
void help(vector<int>&nums,int index, vector<vector<int>>&ans ){
    int n = nums.size();

    if(index == n)
    {
        ans.push_back(nums);
    }
    for(int i =index;i<n ; i++)
    {
        swap(nums[index], nums[i]);
        help(nums,index+1,ans);
        swap(nums[index], nums[i]); // backtrack
    }
    

}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        help(nums,0,ans);
        return ans;
        
    }
};