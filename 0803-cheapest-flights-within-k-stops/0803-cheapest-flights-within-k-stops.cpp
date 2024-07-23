class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto e:flights)
            adj[e[0]].push_back({e[1],e[2]});
        vector<int>dis(n,INT_MAX);
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        dis[src]=0;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stops=it.first;
            int node=it.second.first;
            int cost=it.second.second;
            if(stops>k)continue;
            for(auto ne:adj[node]){
                if(dis[ne.first]>cost+ne.second && stops<=k){
                    dis[ne.first]=cost+ne.second;
                    q.push({stops+1,{ne.first,dis[ne.first]}});
                }
            }
        }
        if(dis[dst]==INT_MAX)
            return -1;
        return dis[dst];
    }
};