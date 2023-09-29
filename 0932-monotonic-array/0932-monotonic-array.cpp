class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n=nums.size();

        for(int i=1;i<n;i++){
            if(nums[i]!=nums[0]){
                if(nums[i]>nums[0])
                    return monotonicIncreasing(nums,i);
                else
                    return monotonicDecreasing(nums,i);
            }
        }
        return true;
    }

    bool monotonicIncreasing(vector<int>& nums, int ind){
        for(int i=ind+1;i<nums.size();i++){
            if(nums[i-1]>nums[i])
                return false;
        }
        return true;
    }

    bool monotonicDecreasing(vector<int>& nums, int ind){
        for(int i=ind+1;i<nums.size();i++){
            if(nums[i-1]<nums[i])
                return false;
        }
        return true;
    }
};