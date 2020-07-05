class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int n=nums.size();
        int prefix[n];
        int max_val,min_val,startindex,arraysize=-1;
        if(nums[0]==0)
            prefix[0]=-1;
        else
            prefix[0]=1;
        max_val=prefix[0];
        min_val=prefix[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i]==0)
                prefix[i]=prefix[i-1]+(-1);
            else
                prefix[i]=prefix[i-1]+1;
            if(prefix[i]>max_val)
                max_val=prefix[i];
            if(prefix[i]<min_val)
                min_val=prefix[i];
        }
        // for(int i=0;i<n;i++)
        //     cout<<prefix[i]<<" ";
        // cout<<min_val<<" "<<max_val<<endl;
        int sizeofhashmap=max_val-min_val+1;
        // cout<<sizeofhashmap<<endl;
        int hash[sizeofhashmap];
        for(int i=0;i<sizeofhashmap;i++)
            hash[i]=-1;
        for(int i=0;i<n;i++){
            if(prefix[i]==0){
                startindex=0;
                arraysize=i+1;
                // cout<<"yo1 for index: "<<i<<endl;

            }
            if(hash[prefix[i]-min_val]==-1){
                hash[prefix[i]-min_val]=i;
                // cout<<"yo2 for index: "<<i<<endl;
            }
            else{
                if(i-hash[prefix[i]-min_val]>arraysize){
                    arraysize=i-hash[prefix[i]-min_val];
                    startindex=hash[prefix[i]-min_val]+1;
                   // cout<<"yo3 for index: "<<i<<endl;
                }
            }
        }
        if(arraysize==-1 )
            return 0;
        return arraysize;
    }
};
