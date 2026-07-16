class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        int n=nums.size();
        vector<int>tmp;
        for(int mask=0;mask<(1<<n);mask++){
            for(int i=0;i<n;i++){
                if(mask&(1<<i))
                    tmp.push_back(nums[i]);
            }
        ans.push_back(tmp);
        tmp={};
        }
        return ans;
    }
};