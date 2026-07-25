class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left=0;
        int right=numbers.size()-1;
        int sum=0;
        while(left<right){
            sum=numbers[left]+numbers[right];
            if(sum<target)
                left++;
            else if(sum>target)
                right--;
            else
                return {left+1,right+1};
        }
        return {};
    }
};