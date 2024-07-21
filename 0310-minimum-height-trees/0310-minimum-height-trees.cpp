class Solution {
public:
    // vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    //     if(n==1)
    //         return {0};
    //     vector<vector<int>>adj(n);
    //     for(auto e:edges){
    //         adj[e[0]].push_back(e[1]);
    //         adj[e[1]].push_back(e[0]);
    //     }
    //     unordered_map<int,vector<int>>mp;
    //     int height=INT_MAX;
    //     for(int i=0;i<n;i++){
    //         vector<int>vis(n,0);
    //         int h = minHeight(i,adj,vis);
    //         mp[h].push_back(i);
    //         height=min(height,h);
    //     }
    //     return mp[height];
    // }

    // int minHeight(int node, vector<vector<int>>&adj, vector<int>&vis){
    //     vis[node]=1;
    //     int height=0;
    //     for(int i=0;i<adj[node].size();i++){
    //         if(!vis[adj[node][i]])
    //             height=max(height,1+minHeight(adj[node][i],adj,vis));
    //     }
    //     return height;
    // }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)
            return {0};
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            indegree[e[0]]++;
            indegree[e[1]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==1){
                q.push(i);
                indegree[i]--;
            }
        }
        vector<int>ans;
        while(!q.empty()){
            ans.clear();
            int size=q.size();
            while(size--){
                int node=q.front();
                ans.push_back(node);
                q.pop();
                for(int i=0;i<adj[node].size();i++){
                    indegree[adj[node][i]]--;
                    if(indegree[adj[node][i]]==1)
                        q.push(adj[node][i]);
                }
            }
        }
        return ans;
    }
};