class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int write=1;
        int lastread=nums[0];
        int k=1;
        for(int read=1;read<nums.size();read++){
            if(nums[read]!=lastread){
                nums[write++]=nums[read];
                lastread=nums[read];
                k++;
            }
        }
        return k;
    }
};