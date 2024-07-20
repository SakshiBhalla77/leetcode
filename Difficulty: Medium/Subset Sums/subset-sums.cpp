//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  void solve(vector<int> arr, vector<int>&ans, int index, int sum )
  {
      int n = arr.size();
      if(index ==n)
      {
          ans.push_back(sum);
          return;
      }
      solve(arr, ans, index+1, sum+arr[index]);
      solve(arr, ans,index+1, sum );
      
  }
    vector<int> subsetSums(vector<int> arr, int n) {
        // Write You
        vector<int> ans;
        solve(arr,ans,0,0); //Code here
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends