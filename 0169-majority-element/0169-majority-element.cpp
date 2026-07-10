class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0;
        int currCandidate=-1;
        for(int i=0;i<nums.size();i++){
            if(cnt==0)
                currCandidate=nums[i];
            currCandidate==nums[i]?cnt++:cnt--;
        }
        return currCandidate;
    }
};