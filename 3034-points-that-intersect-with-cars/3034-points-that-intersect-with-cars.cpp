class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end());
        int l=nums[0][0];
        int r=nums[0][1];
        int len=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i][0]>r){
                len+=(r-l+1);
                l=nums[i][0];
                r=nums[i][1];
            }
            else{
                l=min(l,nums[i][0]);
                r=max(r,nums[i][1]);
            }
        }
        len+=(r-l+1);
        return len;
    }
};