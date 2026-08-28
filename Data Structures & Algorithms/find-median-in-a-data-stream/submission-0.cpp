class MedianFinder {
public:
    priority_queue<int>pq;
    MedianFinder() {
        
    }
    void addNum(int num) {
        pq.push(num);
    }
    
    double findMedian() {
        priority_queue<int,vector<int>,greater<int>>second;
        double ans=0;
        if(pq.size()%2){
            while(pq.size() != second.size()+1){
                second.push(pq.top());
                pq.pop();
            }

            ans=pq.top();

            return ans;
        }

        else{
            while(pq.size() != second.size()){
                second.push(pq.top());
                pq.pop();
            }

            ans= pq.top() + second.top();

            return ans/2;

        }

        return 0;

        
    }
};
