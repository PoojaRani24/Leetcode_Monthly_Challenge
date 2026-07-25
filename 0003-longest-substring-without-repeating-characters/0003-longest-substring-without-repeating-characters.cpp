class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>m;
        int n=s.size();
        int left=0;
        int ans=INT_MIN;
        for(int right=0;right<n;right++){
            if(m.count(s[right]))
                left = max(left,m[s[right]]+1);    
            m[s[right]]=right;
            ans=max(ans, right-left+1);
        }
        if(ans==INT_MIN)
            ans=0;
        return ans;
    }
};