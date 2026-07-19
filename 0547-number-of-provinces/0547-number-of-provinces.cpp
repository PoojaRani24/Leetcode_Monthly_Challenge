class Disjoint{
    vector<int>parent, rank;
    public:
        Disjoint(int n){
            parent.resize(n+1);
            rank.resize(n+1,0);
            for(int i=1;i<=n;i++)
                parent[i]=i;
        }

        int findUParent(int u){
            if(parent[u]==u)
                return u;
            return parent[u]=findUParent(parent[u]);
        }

        void UnionByRank(int u, int v){
            int parentu=findUParent(u);
            int parentv=findUParent(v);
            if(parentu==parentv)
                return;
            if(rank[parentu]<rank[parentv]){
                parent[parentu]=parentv;
            }
            else if (rank[parentv]<rank[parentu])
            {
                parent[parentv]=parentu;
            }
            else 
            {
                parent[parentv]=parentu;
                rank[parentu]++;
            }
            return;
        }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int r=isConnected.size();
        int c=isConnected[0].size();
        Disjoint ds(r+1);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(isConnected[i][j]==1){
                    ds.UnionByRank(i,j);}
            }
        }
        int cnt=0;
        for(int i=0;i<r;i++){
                if(ds.findUParent(i)==i){
                    cnt++;}
            }
        return cnt;
    }
};