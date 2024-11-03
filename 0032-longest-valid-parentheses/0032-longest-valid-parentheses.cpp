#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLen = 0;
        stack<int> st;
        st.push(-1);  // Initialize with -1 as a base for the first valid substring

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                // Push index of '(' to stack
                st.push(i);
            } else {
                // Pop the last '(' index
                st.pop();
                
                if (!st.empty()) {
                    // Calculate the length of the current valid substring
                    maxLen = max(maxLen, i - st.top());
                } else {
                    // No matching '(', so push current index as a boundary
                    st.push(i);
                }
            }
        }
        return maxLen;
    }
};
