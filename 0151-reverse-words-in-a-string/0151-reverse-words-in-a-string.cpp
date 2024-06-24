class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        
        string str = "";
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == ' ') {
                if (!str.empty()) {
                    st.push(str);
                    str = "";
                }
            } else {
                str += s[i];
            }
        }

        // Push the last word if there's any
        if (!str.empty()) {
            st.push(str);
        }

        string ans = "";
        while(st.size() > 1) {
            ans += st.top() + " ";
            st.pop();
        }

        // Add the last word if the stack is not empty
        if (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};
