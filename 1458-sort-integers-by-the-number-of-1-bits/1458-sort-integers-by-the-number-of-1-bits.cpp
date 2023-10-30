class Solution {
public:
    static int count_set_bits(int num){
        int count=0;
        while(num){
            num=num&(num-1);
            count++;
        }
        return count;
    }

    static bool compare(const int &a, const int &b){
        int p=count_set_bits(a);
        int q=count_set_bits(b);
        if(p==q)
            return a<=b;
        return p<q;
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(),arr.end(),compare);
        return arr;
    }
};