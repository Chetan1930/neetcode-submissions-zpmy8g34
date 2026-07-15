class MinStack {
public:
    stack<pair<int,int>>st;

    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty())st.push({val,val});
        else{
            int temp=st.top().second;
            temp=min(temp,val);
            st.push({val,temp});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
        
    }
    
    int getMin() {
        return st.top().second;
    }
};
