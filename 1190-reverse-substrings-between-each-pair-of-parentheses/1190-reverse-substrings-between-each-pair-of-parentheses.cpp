class Solution {
public:
    string reverseParentheses(string s) 
    {
        stack<string> st;
      string ans = "";

    for (auto ch : s) {
        if (ch == '(') {
            // Push the current ans to the stack and reset ans
            st.push(ans);
            ans = "";
        } else if (ch == ')') {
            // Reverse the current ans
            reverse(ans.begin(), ans.end());

            // Add the reversed string to the string at the top of the stack
            if (!st.empty()) {
                ans = st.top() + ans;
                st.pop();
            }
        } else {
            // Add the character to ans
            ans += ch;
        }
    }

    // Return the final answer
    return ans;
    }
};