class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>m;
        int cnt=0;
        for(auto t:tasks){
            m[t]++;
            cnt=max(cnt,m[t]);
        }
        int ans=(cnt-1)*(n+1);
        for(auto e:m) if(e.second==cnt)ans++;
        return max((int)tasks.size(),ans);
    }
};