class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
       vector<int>res;
       for(int i=0;i<nums.size();i++){
        res.push_back(getValue(nums[i],a,b,c)); 
       }
        sort(res.begin(), res.end());
       return res;
    }

    int getValue(int x, int a, int b, int c){
        return (a*x*x) + (b*x) + c;
    }
};