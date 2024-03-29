class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int last_element = INT_MIN;
        stack<int>st;
        for(int i=nums.size()-1;i>=0;i--){
            if(!st.empty() && nums[i]<last_element)
                return true;
            while(!st.empty() && st.top()<nums[i]){
                last_element = st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
    return false;
    }
};