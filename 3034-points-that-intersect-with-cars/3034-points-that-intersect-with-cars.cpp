class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        vector<int>points(102,0);
        for(int i=0;i<nums.size();i++){
            points[nums[i][0]]+=1;
            points[nums[i][1]+1]+=-1;
        }
        int sum=0,len=0;
        for(int i=1;i<=100;i++){
            sum+=points[i];
            cout<<i<<" "<<points[i]<<" "<<sum<<endl;
            if(sum>0)
                len++;
        }
        return len;
    }
};

// 1 3 4 5 6 7
// 1 1 1 -1 -1 -1