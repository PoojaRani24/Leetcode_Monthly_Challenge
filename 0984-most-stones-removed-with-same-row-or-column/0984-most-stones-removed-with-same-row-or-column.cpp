class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int,int>X,Y;
        int n=stones.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            int x=stones[i][0];
            int y=stones[i][1];
            if(X.find(x)!=X.end()){
                adj[X[x]].push_back(i);
                adj[i].push_back(X[x]);
            }
            if(Y.find(y)!=Y.end()){
                adj[Y[y]].push_back(i);
                adj[i].push_back(Y[y]);
            }
            X[x]=i;
            Y[y]=i;
        }

       vector<int>vis(n,0);
       int cnt=0;
       for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt+=dfs(i,vis,adj);
                cnt--;
            }
       }
       return cnt;
    }

    int dfs(int node, vector<int>&vis, vector<vector<int>>&adj){
        vis[node]=1;
        int cnt=1;
        for(int i=0;i<adj[node].size();i++){
            if(!vis[adj[node][i]])
                cnt+=dfs(adj[node][i],vis,adj);
        }
        return cnt;
    }
};