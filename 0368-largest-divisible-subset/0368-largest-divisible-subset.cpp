class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        vector<int>dp(n,1);
        int maxLength=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j] == 0)
                    dp[i]=max(dp[i],dp[j]+1);
            }
            maxLength=max(maxLength,dp[i]);
        }
        vector<int>ans;
        int prev=-1;
        for(int i=n-1;i>=0;i--){
            if(dp[i]==maxLength && (prev==-1 || prev%nums[i]==0)){
                ans.push_back(nums[i]);
                maxLength--;
                prev=nums[i];
            }
        }
        return ans;
    }
};