class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0;
        int sum=0, ans=INT_MAX, tmp=0;
        int n=nums.size();
        for(int right=0;right<n;right++){
            sum+=nums[right];
            while(sum>=target){
                ans=min(ans,right-left+1); 
                sum-=nums[left];
                left++;
            } 
        }
        if(ans==INT_MAX)
            ans=0;
        return ans;
    }
};