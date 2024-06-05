class Solution {
public:
void permu(vector<int>&nums , int index, vector<vector<int>>&result){
    int n = nums.size();
    if(index == n)
    {
        result.push_back(nums);
        return;
    }
    for(int i=index ; i<n; i++){
        swap(nums[index], nums[i]);
        permu(nums,index+1,result);
        swap(nums[index], nums[i]);//backtrack
        
    }
    

}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>result;
        permu(nums,0,result);
        return result;

    }
};