class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>q;
    int n=0;
    KthLargest(int k, vector<int>& nums) {
        n=k;
        for(auto &i:nums){
            q.push(i);
            if(q.size()>k){
                q.pop();
            }
        }

    }
    
    int add(int val) {
        q.push(val);
        if(q.size()>n)q.pop();
        return q.top();
    }
};
