class Solution {
public:
    int bfsUtilityFunc(string& beginWord, string& endWord, unordered_set<string>&wordSet){
        queue<string>q;
        q.push(beginWord);
        int depth=0;
        while(!q.empty()){
            int size=q.size();
            depth++;
            while(size--){
                string word=q.front();
                q.pop();
                for(int i=0;i<word.size();i++){
                    string newWord=word;
                    for(char it ='a'; it<='z';it++){
                        newWord[i]=it;
                        if(newWord==word) continue;
                        if(newWord==endWord)
                            return depth+1;
                        if(wordSet.find(newWord)!=wordSet.end()){
                            q.push(newWord);
                            wordSet.erase(newWord);
                        }
                    }
                }
            }
        }
        return 0;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool endWordExist=false;
        // To avoid picking a word which has already been used
        unordered_set<string>wordSet;
        for(auto it: wordList){
            if(it==endWord)
                endWordExist=true;
            wordSet.insert(it);
        }
        if(!endWordExist)
            return 0;
        return bfsUtilityFunc(beginWord, endWord, wordSet);
    }
};