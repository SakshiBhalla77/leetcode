//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  void helper(vector<int>arr , int index, int sum , vector<int>&ans)
  {
      int n = arr.size();
      if(index == n) 
      {
          ans.push_back(sum);
          return;
      }
      helper(arr , index+ 1, sum  + arr[index], ans);
      helper(arr , index+ 1, sum , ans);
      
  }
    vector<int> subsetSums(vector<int> arr, int n) {
        // Write Your Code here
        vector<int> ans;
        helper(arr, 0, 0, ans);
        //sort(ans.begin(), ans.end());
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