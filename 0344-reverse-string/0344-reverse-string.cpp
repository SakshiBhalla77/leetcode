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
    // time O(N) SPACE O(N)
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



/*
//RECURSIVE APPROACH 

void reverseString(vector<char>& s) 
{
    int n = s.size();
    reverse(s,0,n-1);
    
    
}
void reverse(vector<char>& s, int i , int j)
{
   if(i<j){
    swap(s[i],s[j]);
    reverse(s, i + 1, j - 1);
   }
}
*/
};