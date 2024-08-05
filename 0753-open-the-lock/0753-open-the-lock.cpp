class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map<char,char>next,prev;
        next={{'1','2'},{'2','3'},{'3','4'},{'4','5'},{'5','6'},{'6','7'},{'7','8'},{'8','9'},{'9','0'},{'0','1'}};
        prev={{'1','0'},{'2','1'},{'3','2'},{'4','3'},{'5','4'},{'6','5'},{'7','6'},{'8','7'},{'9','8'},{'0','9'}};
        unordered_set<string>vis;
        for(int i=0;i<deadends.size();i++){
            if(deadends[i]=="0000")
                return -1;
            vis.insert(deadends[i]);
        }
        queue<string>q;
        q.push("0000");
        vis.insert("0000");
        int cnt=0;
        while(!q.empty()){
            cnt++;
            int size=q.size();
            while(size--){
                string comb=q.front();
                if(comb==target)
                    return cnt-1;
                q.pop();
                string nextComb, prevComb;
                for(int i=0;i<4;i++){
                    nextComb=comb, prevComb=comb;
                    nextComb[i]=next[comb[i]];
                    if(vis.find(nextComb)==vis.end())
                    {
                        q.push(nextComb);
                        vis.insert(nextComb);
                    }
                    nextComb=comb;
                    prevComb[i]=prev[comb[i]];
                    if(vis.find(prevComb)==vis.end())
                    {
                        q.push(prevComb);
                        vis.insert(prevComb);
                    }
                    prevComb=comb;
                }
            }
        }
        return -1;
    }
};