class Solution {
public:
    struct Compare{
        bool operator()(pair<int,string>&a, pair<int,string>&b){
            if(a.first==b.first)
                return a.second>b.second;
            return a.first>b.first;
        }
    };
    
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n= watchedVideos.size();
        if(n==0)
            return {};
        queue<int>q;
        int lev=0;
        vector<int>vis(n,0);
        unordered_map<string,int>m;
        q.push(id);
        vis[id]=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int friendId=q.front();
                q.pop();
                if(lev!=level){
                    vis[friendId]=1;
                    for(auto i:friends[friendId]){
                        if(!vis[i]){
                            q.push(i);
                            vis[i]=1;
                        }
                    }
                }
                else{
                    for(auto vid:watchedVideos[friendId])m[vid]++;
                }
            }
            lev++;
        }

        vector<string>ans;
        vector<pair<int,string>>v;
        for(auto it=m.begin();it!=m.end();it++)
            v.push_back({it->second,it->first});
        sort(v.begin(),v.end());
        for(auto it:v)ans.push_back(it.second);
        return ans;
    }
};