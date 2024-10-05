class Solution {
public:
/*
// TIME = O(N) SPACE O(1) - iterative solution
    void reverseString(vector<char>& s) {
        int n = s.size();
        int i =0; int j = n-1;
       
        while(i<=j){
            swap(s[i],s[j]);
            i = i+1; 
            j = j-1;
        }
        
        
    }
    */

    // STACK USE KRKE
void reverseString(vector<char>& s) 
{
    stack<char>st;
    for(int i =0; i<s.size();i++)
    {
        st.push(s[i]);
    }
    for(int i =0; i<s.size();i++)
    {
        s[i] = st.top();
        st.pop();
        
    }
}

};