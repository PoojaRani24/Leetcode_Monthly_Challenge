class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if(n<3)
            return n;
        long long int msb=0;
        while(n){
            n=n/2;
            msb++;}
        cout<<msb<<endl;
        int ans=pow(2,msb);
        return ans;
    }
};