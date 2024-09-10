class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        int ans=0, curVal=0, sign=1;
        for(auto ch:s){
            if(isdigit(ch)){
                curVal=curVal*10+(ch-'0');  
            }
            else if(ch=='+' || ch=='-'){
                ans+=(curVal*sign);
                curVal=0;
                sign=-1;
                if(ch=='+')
                    sign=1;
            }
            else if(ch=='('){
                st.push(ans);
                st.push(sign);
                ans=0;
                curVal=0;
                sign=1;
            }
            else if(ch==')'){
                ans=ans+(curVal*sign);
                curVal=0;
                sign=1;
                ans=ans*(st.top());
                st.pop();
                ans+=st.top();
                st.pop();
            }
        }
        ans+=(curVal*sign);
        return ans;
    }
};