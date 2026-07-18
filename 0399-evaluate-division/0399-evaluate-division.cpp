class Solution {
public:
    unordered_map<string,vector<pair<string,double>>>adj;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // construct adjacency list
        for(int i=0;i<equations.size();i++){
            string u = equations[i][0];
            string v = equations[i][1];
            double w = values[i];
            adj[u].push_back({v,w});
            adj[v].push_back({u,1.0/w});
        }

        vector<double>ans;
        for(int i=0;i<queries.size();i++){
            string u = queries[i][0];
            string v = queries[i][1];
            double w = -1;
            if(!adj.count(u) || !adj.count(v)){
                ans.push_back(w);
                continue;
            }
            unordered_set<string>vis;
            w = dfs(u,v,vis, 1);
            ans.push_back(w);
        }
        return ans;
    }

    double dfs(string u, string v, unordered_set<string>&vis, double w){
        double ans;
        if(u==v)
            return w;
        vis.insert(u);
        for(auto it:adj[u]){
            if(!vis.count(it.first)){
                ans = dfs(it.first,v,vis,w*it.second);
                if(ans!=-1)
                    return ans;
            }
        }
        return -1;
    }
};