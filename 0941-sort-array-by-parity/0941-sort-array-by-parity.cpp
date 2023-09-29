class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int l=0,r=n-1,m=0;
        while(m<=r){
            if(nums[m]%2==0){
                l++;
                m++;
            }
            else{
                int tmp=nums[m];
                nums[m]=nums[r];
                nums[r]=tmp;
                r--;
            }
        }
        return nums;
    }
};

/*
4213
*/