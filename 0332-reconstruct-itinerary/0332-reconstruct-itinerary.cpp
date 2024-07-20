class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n=tickets.size();
        sort(tickets.begin(),tickets.end());
        unordered_map<string,vector<string>>adj;
        for(int i=0;i<n;i++){
            if (adj.find(tickets[i][0])==adj.end())
                adj[tickets[i][0]].push_back("1");
            adj[tickets[i][0]].push_back(tickets[i][1]);
        }

        stack<string>st;
        st.push("JFK");
        vector<string>ans;
        while(!st.empty()){
            string node=st.top();
            if(adj[node].size()>1 && stoi(adj[node][0])<adj[node].size()){
                st.push(adj[node][stoi(adj[node][0])]);
                adj[node][0]=to_string(stoi(adj[node][0])+1);
            }
            else{
                st.pop();
                ans.push_back(node);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};