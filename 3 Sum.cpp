class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        if(nums.size()<3)
            return ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int low=i+1;
            int high=nums.size()-1;
            int val=0-nums[i];
            vector<int>temp;
            while(low<high){
                
                if(nums[low]+nums[high]==val){
                    temp.push_back(nums[i]);
                    temp.push_back(nums[low]);
                    temp.push_back(nums[high]);
                    ans.push_back(temp);
                    temp.clear();
                    while(low<high && nums[low]==nums[low+1])
                        low++;
                    while(low<high && nums[high]==nums[high-1])
                        high--;
                    low++;
                    high--;
                }
                else if(nums[low]+nums[high]>val)
                    high--;
                else
                    low++;
            }
        }
        return ans;
    }
};
