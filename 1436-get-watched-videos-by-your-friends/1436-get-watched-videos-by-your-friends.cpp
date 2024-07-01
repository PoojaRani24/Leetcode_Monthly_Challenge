class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n=friends.size();
        queue<int>q;
        long lev=0;
        vector<int>vis(n);
        q.push(id);
        vis[id]=1;
        while(!q.empty() && lev!=level){
            int size=q.size();
            while(size--){
                int friendInd=q.front();
                q.pop();
                for(int i=0;i<friends[friendInd].size();i++){
                    if(!vis[friends[friendInd][i]]){
                        vis[friends[friendInd][i]]=1;
                        q.push(friends[friendInd][i]);
                    }
                }
            }
            lev++;
        }

        unordered_map<string,int>m;
        while(!q.empty()){
            int friendInd=q.front();
            q.pop();
            for(int i=0;i<watchedVideos[friendInd].size();i++){
                m[watchedVideos[friendInd][i]]++;
            }
        }

        vector<pair<int,string>>movies;
        vector<string>ans;
        for(auto i:m)movies.push_back({i.second,i.first});
        sort(movies.begin(),movies.end());
        for(auto i:movies)ans.push_back(i.second);
        return ans;
    }
};