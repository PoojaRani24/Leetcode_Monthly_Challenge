class Solution {
public:
    string reverseWords(string s) {
        stack<char>st;
        int n = s.size();
        string res="";
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                while(!st.empty()){
                    char ch = st.top();
                    st.pop();
                    res+=ch;
                }
                res+=s[i];
            }
            else
                st.push(s[i]);
        }

        while(!st.empty()){
            char ch = st.top();
            st.pop();
            res+=ch;
        }
        return res;
    }
};