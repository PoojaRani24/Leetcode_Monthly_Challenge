class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum=0;
        int maxSumSoFar=INT_MIN;
        for(int i=0;i<nums.size();i++){
            currentSum+=nums[i];
            maxSumSoFar=max(currentSum,maxSumSoFar);
            if(currentSum<0)
                currentSum=0;
        }
        return maxSumSoFar;
    }
};