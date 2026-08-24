class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>q;
    KthLargest(int k, vector<int>& nums) {
        
        for(auto &i:nums){
            q.push(i);
            if(q.size()>k){
                q.pop();
            }
        }

    }
    
    int add(int val) {
        q.push(val);
        cout<<q.top()<<endl;
        q.pop();
        cout<<q.top();
        return q.top();
    }
};
