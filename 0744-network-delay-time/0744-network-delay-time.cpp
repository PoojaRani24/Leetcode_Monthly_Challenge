class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<times.size();i++) adj[times[i][0]].push_back({times[i][1],times[i][2]});
        vector<int>dis(n+1,INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0,k});
        dis[k]=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int u=it.second;
            int wt=it.first;
            if(dis[u]<wt)
                continue;
            for(auto e:adj[u]){
                int v=e.first;
                int edgeWt=e.second;
                if(dis[v]>dis[u]+edgeWt){
                    dis[v]=dis[u]+edgeWt;
                    pq.push({dis[v],v});
                }
            }
        }

        int ans=INT_MIN;
        for(int i=1;i<=n;i++){
            if(dis[i]==INT_MAX)
                return -1;
            ans=max(ans,dis[i]);
        }
        return ans;
    }
};