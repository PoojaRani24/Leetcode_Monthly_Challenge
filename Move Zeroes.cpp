class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size()==1)
            return;
        int i=0;
        int n=nums.size();
        int z=0;
        while(i<n){
            if(nums[i]==0)
                i++;
            else if(z<i)
            {
                nums[z]=nums[i];
                i++;
                z++;
            }
            else{
               i++;
                z++;
            }
        }
        while(z<n){
            nums[z]=0;
            z++;
        }
        //return nums;
    }
};
