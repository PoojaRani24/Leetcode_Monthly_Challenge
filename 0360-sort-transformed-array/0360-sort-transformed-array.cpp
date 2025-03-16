class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
       vector<int>res;
       int left=0,right=nums.size()-1;
       if(a>0){
        //Upward parabola
        while(left<=right){
            int leftVal=getValue(nums[left],a,b,c);
            int rightVal=getValue(nums[right],a,b,c);
            if(leftVal>=rightVal){
                res.push_back(leftVal);
                left++;
            }
            else{
                res.push_back(rightVal);
                right--;
            }
        }
        reverse(res.begin(),res.end());
       }
       else{
        //Downward parabola
        while(left<=right){
            int leftVal=getValue(nums[left],a,b,c);
            int rightVal=getValue(nums[right],a,b,c);
            if(leftVal<=rightVal){
                res.push_back(leftVal);
                left++;
            }
            else{
                res.push_back(rightVal);
                right--;
            }
        }
       }
       return res;
    }

    int getValue(int x, int a, int b, int c){
        return (a*x*x) + (b*x) + c;
    }
};