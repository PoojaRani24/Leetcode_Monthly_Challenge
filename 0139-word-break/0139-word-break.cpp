class Solution {
public:
    bool wordBreakDP(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string>st(wordDict.begin(), wordDict.end());
        vector<int>dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                if(dp[j]==1 && st.find(s.substr(j,i-j))!=st.end()){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n];
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string>st(wordDict.begin(), wordDict.end());
        vector<int>dp(n,0);
        for(int i=0;i<n;i++){
            for(auto word:st){
                if(i<word.size()-1)
                    continue;
                if(i==word.size()-1 || dp[i-word.size()]){
                    if(s.substr(i - word.length() + 1, word.length()) ==
                        word){
                        dp[i]=1;
                        break;
                    }
                }
            }
        }
        return dp[n-1];
    }
};