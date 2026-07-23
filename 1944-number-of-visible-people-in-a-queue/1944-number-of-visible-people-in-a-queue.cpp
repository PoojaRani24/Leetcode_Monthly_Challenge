class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int>st;
        int n = heights.size();
        vector<int>vispeople(n,0);
        for(int i=n-1;i>=0;i--){
            int ans=0;
            while(!st.empty() && st.top()<heights[i]){
                st.pop();
                ans++;
            }
            if(!st.empty())
                ans++;
            st.push(heights[i]);
            vispeople[i]=ans;
        }
        return vispeople;
    }
};