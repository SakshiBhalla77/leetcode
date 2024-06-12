//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++
bool solve(int index, int target, vector<int> &arr ,vector<vector<int>>&dp)
{
    if(target == 0) return true;
    if(index ==0)   return (arr[0] == target);
    if(dp[index][target] != -1) return dp[index][target];
    
    
    bool notTake = solve(index-1, target, arr,dp);
    bool Take = false ;
    if(target >= arr[index]) Take = solve(index-1, target - arr[index], arr,dp);
    
    return dp[index][target] = Take || notTake;
    
}

class Solution{   
public:
    bool isSubsetSum( vector<int>arr, int sum){
        // code here 
       
        int index = arr.size();
         vector<vector<int>> dp(index, vector<int> (sum+1,-1));
        return solve(index-1, sum , arr,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends