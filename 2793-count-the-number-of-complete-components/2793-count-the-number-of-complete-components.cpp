class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int cnt=0;
        vector<int>vis(n,0);
        int nodeCnt=0, edgeCnt=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                nodeCnt=0;
                edgeCnt=0;
                dfs(i,adj,vis,nodeCnt,edgeCnt);
                cout<<nodeCnt<<" "<<edgeCnt<<endl;
                if(edgeCnt==((nodeCnt*(nodeCnt-1))))
                    cnt++;
            }
        }
        return cnt;
    }

    void dfs(int ind, vector<vector<int>>&adj, vector<int>&vis, int&nodeCnt, int&edgeCnt){
        vis[ind]=1;
        nodeCnt++;
        edgeCnt+=adj[ind].size();
        for(int i=0;i<adj[ind].size();i++){
            if(!vis[adj[ind][i]]){
                dfs(adj[ind][i],adj,vis,nodeCnt,edgeCnt);
            }
        }
    }
};