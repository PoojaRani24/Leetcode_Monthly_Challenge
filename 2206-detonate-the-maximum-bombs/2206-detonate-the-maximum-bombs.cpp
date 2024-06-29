class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(boombsLiesWithinRange(bombs[i],bombs[j])){
                    adj[i].push_back(j);
                }
            }
        }

        int boombDiffused=0;
        int maxBoombDiffused=0;
        for(int i=0;i<n;i++){
            vector<int>vis(n);
            boombDiffused= dfs(i,adj,vis);
            maxBoombDiffused = max(maxBoombDiffused,boombDiffused);
        }
        return maxBoombDiffused;
    }

    bool boombsLiesWithinRange(vector<int>boombA, vector<int>boombB){
        double distanceBetweenBoombsXAxis = pow(boombA[0]-boombB[0],2);
        double distanceBetweenBoombsYAxis = pow(boombA[1]-boombB[1],2);
        double distanceBetweenBoombs = sqrt((double)(distanceBetweenBoombsXAxis + distanceBetweenBoombsYAxis));
        int BoombARange = boombA[2];
        return distanceBetweenBoombs<=BoombARange;
    }

    int dfs(int boomb, vector<vector<int>>&adj, vector<int>&vis){
        vis[boomb]=1;
        int boombDiffused = 1;
        for(int i=0;i<adj[boomb].size();i++){
            if(!vis[adj[boomb][i]])
                boombDiffused+=dfs(adj[boomb][i],adj,vis);
        }
        return boombDiffused;
    }
};