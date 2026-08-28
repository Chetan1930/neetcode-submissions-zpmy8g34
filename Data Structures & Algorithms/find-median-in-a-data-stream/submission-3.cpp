class MedianFinder {
public:
    priority_queue<int>pq;
    priority_queue<int,vector<int>,greater<int>>second;

    MedianFinder() {
        
    }
    void addNum(int num) {
       
        if(pq.empty() || pq.top() < num){
            second.push(num);
        }
        else pq.push(num);

        if (pq.size() > second.size() + 1) {
            second.push(pq.top());
            pq.pop();
        }

        else if (second.size() > pq.size() + 1) {
            pq.push(second.top());
            second.pop();
        }   

    }
    
    double findMedian() {
        if(pq.size()>second.size()){
            return pq.top();
        }
        if(second.size()>pq.size()){
            return second.top();
        }

        double ans = pq.top() + second.top();

        return ans/2.0;
        
    }
};
