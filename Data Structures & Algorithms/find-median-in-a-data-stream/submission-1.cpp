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
        priority_queue<int>temp=pq;
        double ans=0;
        if(temp.size()%2){
            while(temp.size() != second.size()+1){
                second.push(temp.top());
                temp.pop();
            }

            ans=temp.top();
            temp=temp;
            return ans;
        }

        else{
            while(temp.size() != second.size()){
                second.push(temp.top());
                temp.pop();
            }

            ans= temp.top() + second.top();

            return ans/2;

        }

        return 0;

        
    }
};
