class Solution {
public:
    unordered_set<string>m;
    unordered_map<string,bool>memoization;
    bool wordBreak(string s, vector<string>& wordDict) {
        for(int i=0;i<wordDict.size();i++)
            m.insert(wordDict[i]);
        return wb(s);
    }
    
    bool wb(string s){
        if(s.size()==0)
            return true;
        if(memoization.find(s)!=memoization.end())
            return memoization[s];
        for(int i=0;i<s.size();i++){
            string temp=s.substr(0,i+1);
            if(m.find(temp)!=m.end() && wb(s.substr(i+1))){
                memoization[s.substr(i+1)]=true;
                return true;
            }
            else
                 continue;
        }
        memoization[s]=false;
        return false;
    }
};
