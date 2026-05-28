class MedianFinder {
public:
    priority_queue<int>leftMax;
    priority_queue<int,vector<int>,greater<int>>rightMin;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(leftMax.empty() || num<leftMax.top()){
            leftMax.push(num);
        }else{
            rightMin.push(num);
        }
        //always maintain leftMax heap size one greater than rightMin size
        if(abs((int)rightMin.size()-(int)leftMax.size())>1){
            rightMin.push(leftMax.top());
            leftMax.pop();
        }else if(leftMax.size()<rightMin.size()){
            leftMax.push(rightMin.top());
            rightMin.pop();
        }
    }
    
    double findMedian() {
        int n=leftMax.size()+rightMin.size();
        if(n&1){
            return leftMax.top();
        }
        return (double)(leftMax.top()+rightMin.top())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */