class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int>m;
        int n=s.size();
        int left=0;
        int ans=INT_MIN;
        for(int right=0;right<n;right++){
            m[s[right]]++;
            while(m[s[right]]>1){
                m[s[left]]--;
                left++;
            }
            ans=max(ans, right-left+1);
        }
        if(ans==INT_MIN)
            ans=0;
        return ans;
    }
};