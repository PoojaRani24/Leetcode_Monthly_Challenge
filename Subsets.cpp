class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        int p=pow(2,n);
        for(int i=0;i<p;i++){
            vector<int>tem;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    tem.push_back(nums[j]);
                }
            }
            ans.push_back(tem);
        }
        return ans;
    }
};
