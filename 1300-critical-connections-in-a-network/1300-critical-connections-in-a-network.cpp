class Solution {
public:
    int timer=1;
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        vector<int>time(n,0), lowestTime(n,INT_MAX);
        vector<int>vis(n,0);
        vector<vector<int>>ans;
        dfs(1,-1,adj,vis,time,lowestTime,ans);
        return ans;
    }

    void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>&vis,vector<int>&time,vector<int>&lowestTime,vector<vector<int>>&ans){
        vis[node]=1;
        time[node]=timer;
        lowestTime[node]=timer;
        timer++;
        for(int i=0;i<adj[node].size();i++){
            if(adj[node][i]==parent)continue;
            if(!vis[adj[node][i]]){
                dfs(adj[node][i],node,adj,vis,time,lowestTime,ans);
                lowestTime[node]=min(lowestTime[node],lowestTime[adj[node][i]]);
                if(lowestTime[adj[node][i]]>time[node])
                    ans.push_back({node,adj[node][i]});
            }
            else{
                lowestTime[node]=min(lowestTime[node],lowestTime[adj[node][i]]);
            }
        }
    }
};