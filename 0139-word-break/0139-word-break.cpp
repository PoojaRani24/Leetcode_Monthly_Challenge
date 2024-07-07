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

    bool wordBreakBetter(string s, vector<string>& wordDict) {
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
    
    struct TrieNode{
        bool isEnd;
        unordered_map<char,TrieNode*>children;
        TrieNode(){
            isEnd=false;
        }
    };

    bool wordBreak(string s, vector<string>& wordDict) {
        TrieNode* root=new TrieNode();
        int m=wordDict.size();
        int n=s.size();
        TrieNode* curr;
        // Create trie
        for(auto word:wordDict){
            curr=root;
            for(auto ch:word){
                if(curr->children.find(ch)==curr->children.end()){
                    curr->children[ch]=new TrieNode();
                }
                curr=curr->children[ch];
            }
            curr->isEnd=true;
        }

        vector<int>dp(n,0);
        for(int i=0;i<n;i++){
            if(i==0 || dp[i-1]==1){
                curr=root;
                for(int j=i;j<n;j++){
                    if(curr->children.find(s[j])==curr->children.end())
                        break;
                    curr=curr->children[s[j]];
                    if(curr->isEnd)
                        dp[j]=true;
                }
            }
        }
        return dp[n-1];
    }
};