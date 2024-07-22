class MovingAverage {
public:
    int capacity, sum=0;
    deque<int>dq;
    MovingAverage(int size) {
        capacity=size;
    }
    
    double next(int val) {
        if(dq.size()==capacity){
            sum-=dq.front();
            dq.pop_front();
        }
        sum+=val;
        dq.push_back(val);
        return (double)sum/(double)dq.size();
        
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */