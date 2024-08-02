class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<vector<int>> ans;
        vector<int>ds;
        combinationSumUtil(0,target,candidates,ans,ds);
        return ans;
    }

    void combinationSumUtil(int ind, int target, vector<int>& candidates, vector<vector<int>>&ans, vector<int>ds){
        if(target==0)
            {
                ans.push_back(ds);
                return;
            }
        if(ind==candidates.size())
            return;

        // Pick
        if(target-candidates[ind]>=0){
            ds.push_back(candidates[ind]);
            combinationSumUtil(ind,target-candidates[ind],candidates,ans,ds);
            ds.pop_back();
        }

        // Don't pick
        combinationSumUtil(ind+1,target,candidates,ans,ds);
    }
};