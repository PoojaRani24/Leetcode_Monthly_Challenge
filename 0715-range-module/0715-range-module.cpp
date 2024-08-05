class RangeModule {
public:
    map<int,int>m;
    RangeModule() {}
    
    void addRange(int left, int right) {
        auto it =m.upper_bound(left);
        if(it!=m.begin() && prev(it)->second>=left)
            it--;
        while(it!=m.end() && it->first<=right){
            left=min(left,it->first);
            right=max(right,it->second);
            it=m.erase(it);
        }
        m[left]=right;
    }
    
    bool queryRange(int left, int right) {
        auto it =m.upper_bound(left);
        if(it==m.begin()) return false;
            it--;
        return it->second>=right;
    }
    
    void removeRange(int left, int right) {
        auto it =m.upper_bound(left);
        if(it!=m.begin() && prev(it)->second>=left)
            it--;
        vector<pair<int,int>>toAdd;
        while(it!=m.end() && it->first<=right){
            if(left>it->first)
                toAdd.emplace_back(it->first,left);
            if(it->second>right)
                toAdd.emplace_back(right,it->second);
            it=m.erase(it);
        }
        for(auto p:toAdd)
            m[p.first]=p.second;
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */