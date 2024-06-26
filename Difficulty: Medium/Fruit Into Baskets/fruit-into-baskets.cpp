//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int totalFruits(int N, vector<int> &fruits) 
    {
        //int k = 2;
        int l=0, r =0 , maxi = 0; 
        map<int,int> mpp;
        while(r < fruits.size())
        {
            mpp[fruits[r]] ++ ; 
            if(mpp.size() > 2)
            {
                while(mpp.size() > 2)
                {
                    mpp[fruits [l]]--;
                    if(mpp[fruits[l]] == 0)
                    mpp.erase(fruits[l]);
                    
                    l++;
                
                }
            }
            if(mpp.size()<= 2){
                maxi = max(maxi , r-l+1);
            }
            r++;
        }
        return maxi;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> fruits(N);
        for (int i = 0; i < N; i++) cin >> fruits[i];
        Solution obj;
        cout << obj.totalFruits(N, fruits) << endl;
    }
    return 0;
}

// } Driver Code Ends