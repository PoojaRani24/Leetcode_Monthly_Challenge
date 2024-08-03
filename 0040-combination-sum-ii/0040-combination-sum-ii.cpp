class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
        sort(c.begin(),c.end());
        vector<vector<int>>ans;
        // set<vector<int>>s;
        vector<int>ds;
        combinationSum2Utils(0,c,t,ans,ds);
        // for(auto it:s)
        //     ans.push_back(it);
        return ans;
    }

    void combinationSum2Utils(int ind, vector<int>& c, int t,vector<vector<int>>&ans,vector<int>ds){
        if(t==0){
           ans.push_back(ds);
           return; 
        }
        if(ind==c.size())
            return;
        
        for(int i=ind;i<c.size();i++){
            if(i>ind && c[i-1]==c[i])continue;
            if(t-c[i]<0)break;
            ds.push_back(c[i]);
            combinationSum2Utils(i+1,c,t-c[i],ans,ds);
            ds.pop_back();
        }
    }
};