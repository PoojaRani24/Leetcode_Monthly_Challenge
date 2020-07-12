class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<pair<int,int>>v;
        int count=0;
        for(int i=0;i<nums.size();){
            if(nums[i]==0)
                i++;
            else{
                int start=i;
                int c=0;
                while(i<nums.size() && nums[i]==1)
                {
                    i++;
                    c++;
                }
                v.push_back({start,i-1});
                if(c>count)
                    count=c;
            }
        }
        for(int i=0;i<v.size();i++)
            cout<<v[i].first<<" "<<v[i].second<<endl;
        if(v.size()==0)
            return 0;
        else if(v.size()==1){
            if(v[0].second-v[0].first+1==nums.size())
            return nums.size()-1;
            else
                return v[0].second-v[0].first+1;
        }
        else{
            for(int i=0;i<v.size()-1;i++){
                if(v[i+1].first-v[i].second>2)continue;
                else
                {
                    if(v[i+1].second-v[i].first>count)
                        count=v[i+1].second-v[i].first;
                }
            }
            return count;
        }
        //return 0;
    }
};
