class Solution {
public:
    vector<vector<string>> findLaddersTLE(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        unordered_set<string>wordSet(wordList.begin(),wordList.end());
        vector<string>usedWordPerLevel;
        queue<vector<string>>q;
        vector<vector<string>>ans;
        // For level 0
        usedWordPerLevel.push_back(beginWord);
        q.push({beginWord});
        while(!q.empty()){
            int size=q.size();
            for(auto usedWord:usedWordPerLevel)
                wordSet.erase(usedWord);
            usedWordPerLevel.clear();
            while(size--){
                vector<string>seq=q.front();
                q.pop();
                string word=seq.back();
                for(int i=0;i<word.size();i++){
                    string newWord=word;
                    for(char ch='a';ch<='z';ch++){
                        newWord[i]=ch;
                        if(newWord==word)continue;
                        if(wordSet.count(newWord)){
                            usedWordPerLevel.push_back(newWord);
                            seq.push_back(newWord);
                            q.push(seq);
                            if(newWord==endWord){
                                if(ans.size()==0)
                                    ans.push_back(seq);
                                else if(seq.size()==ans[0].size())
                                    ans.push_back(seq);
                            }
                            seq.pop_back();
                        }
                    }
                }
            }
        }
        return ans;
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        unordered_set<string>wordSet(wordList.begin(),wordList.end());
        unordered_map<string,int>wordMap;
        queue<string>q;
        vector<vector<string>>ans;
        q.push(beginWord);
        wordSet.erase(beginWord);
        int depth=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                string word=q.front();
                q.pop();
                wordMap[word]=depth;
                int len=word.size();
                for(int i=0;i<len;i++){
                    string newWord=word;
                    for(char ch='a';ch<='z';ch++){
                        newWord[i]=ch;
                        if(newWord==word)continue;
                        else if(wordSet.count(newWord)){
                            q.push(newWord);
                            wordSet.erase(newWord);
                        }
                    }
                }
            }
            depth++;
        }
    
    vector<string>seq;
    if(wordMap.find(endWord)!=wordMap.end()){
        seq.push_back(endWord);
        dfs(endWord,wordMap,ans,beginWord,seq);
    }
    return ans;
    }

    void dfs(string& word, unordered_map<string,int>&wordMap, vector<vector<string>>&ans, string& beginWord, vector<string>&seq){
        if(word==beginWord){
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
        }
        int len=word.size();
        int depth=wordMap[word];
        for(int i=0;i<len;i++){
            string newWord=word;
            for(char ch='a';ch<='z';ch++){
                newWord[i]=ch;
                if(wordMap.find(newWord)!=wordMap.end() && wordMap[newWord]+1 == depth){
                    seq.push_back(newWord);
                    dfs(newWord, wordMap, ans, beginWord, seq);
                    seq.pop_back();
                }
            }
        }
    }
};