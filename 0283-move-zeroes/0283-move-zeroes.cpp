class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int write=0;
        int n= nums.size();
        int cnt=0;
        for(int read=0;read<n;read++){
            if(nums[read]!=0){
                nums[write]=nums[read];
                write++;
            }
            else
                cnt++;
        }

        int ind=n-1;
        while(cnt){
            nums[ind] = 0;
            ind--;
            cnt--;
        }
    }
};