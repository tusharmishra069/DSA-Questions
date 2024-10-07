class Solution {
public:
    int minLength(string s) {
        stack<char> st;
    for (char c : s) {
        if (!st.empty()) {
            char top = st.top();
            if ((top == 'A' && c == 'B') || (top == 'C' && c == 'D')) {
                st.pop();  
            } else {
                st.push(c); 
            }
        } else {
            st.push(c);  
        }
    }
    
    return st.size();
    }
};