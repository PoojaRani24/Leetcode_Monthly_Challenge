class DSU{
    public:
        vector<int>parent;
        vector<int>rank;
        DSU(int n){
            parent.resize(n+1,0);
            rank.resize(n+1,0);
            for(int i=0;i<=n;i++)
                parent[i]=i;
            }
        
        int findUParent(int u){
            if(parent[u]!=u)
                parent[u]=findUParent(parent[u]);
            return parent[u];
        }

        bool unionByRank(int u, int v){
            int parentu = findUParent(u);
            int parentv = findUParent(v);
            if(parentu==parentv)
                return true;
            if(rank[parentu]<rank[parentv])
                parent[parentu]=parentv;
            else if(rank[parentv]<rank[parentu])
                parent[parentv]=parentu;    
            else{
                parent[parentv]=parentu;    
                rank[parentu]++;
            }
        return false;
        }
    };

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=1001;
        DSU ds(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            if(ds.unionByRank(u,v))
                return {u,v};
        }
        return {};
    }
};